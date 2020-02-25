/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Error.hpp"
#include "nts/Factory.hpp"

static void comment(std::string& string)
{
    if (string.empty()) return;

    std::string::iterator it = std::find(string.begin(), string.end(), '#');

    string.erase(it, string.end());
}

static void spaces(std::string& string)
{
    if (string.empty()) return;

    std::string::iterator it = std::unique(string.begin(), string.end(),
        [](char lhs, char rhs) { return (isspace(lhs) && isspace(rhs)); });

    string.erase(it, string.end());

    std::replace_if(
        string.begin(), string.end(), [](char c) { return isspace(c); }, ' ');
}

static void trim(std::string& string)
{
    if (string.empty()) return;

    std::string::iterator left = std::find_if(
        string.begin(), string.end(), [](char c) { return !isspace(c); });

    string.erase(string.begin(), left);

    std::string::reverse_iterator right = std::find_if(
        string.rbegin(), string.rend(), [](char c) { return !isspace(c); });

    string.erase(right.base(), string.end());
}

static std::vector<std::string> split(const std::string& string, char delim)
{
    std::istringstream stream(string);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(stream, token, delim)) tokens.push_back(token);

    return tokens;
}

static bool isNumber(const std::string& string)
{
    for (const auto& c : string)
        if (!isdigit(c)) return false;

    return true;
}

nts::Circuit& parser::Parser::parse(const std::string& path)
{
    this->fill(path);
    this->clean();
    this->generate();

    return this->_circuit;
}

void parser::Parser::fill(const std::string& path)
{
    std::ifstream file(path);
    std::string line;

    for (std::size_t i = 1; std::getline(file, line); ++i)
        this->_lines[i] = line;
    this->_file = path;
}

void parser::Parser::clean()
{
    for (auto it = this->_lines.begin(); it != this->_lines.end();) {
        comment(it->second);
        spaces(it->second);
        trim(it->second);

        if (it->second.empty())
            it = this->_lines.erase(it);
        else
            ++it;
    }
}

void parser::Parser::generate()
{
    this->checkLabels();
    this->addComponents();
    this->linkComponents();
}

void parser::Parser::checkLabels()
{
    bool chipsetsLabel = false, linksLabel = false;

    for (const auto& line : this->_lines) {
        if (line.second == CHIPSETS_LABEL) {
            if (chipsetsLabel)
                throw Error(
                    this->_file, line.first, ERR_DUPLICATE_CHIPSETS_LABEL);

            chipsetsLabel = true;
        }

        if (line.second == LINKS_LABEL) {
            if (linksLabel)
                throw Error(this->_file, line.first, ERR_DUPLICATE_LINKS_LABEL);
            if (!chipsetsLabel)
                throw Error(this->_file, line.first, ERR_LINKS_BEFORE_CHIPSETS);

            linksLabel = true;
        }
    }

    if (!chipsetsLabel) throw Error(this->_file, 0, ERR_NO_CHIPSETS_LABEL);
    if (!linksLabel) throw Error(this->_file, 0, ERR_NO_LINKS_LABEL);
}

void parser::Parser::addComponents()
{
    bool section = false;

    for (const auto& line : this->_lines) {
        if (line.second == CHIPSETS_LABEL) {
            section = true;
            continue;
        }
        if (!section) continue;
        if (line.second == LINKS_LABEL) break;

        std::vector<std::string> tokens = split(line.second, ' ');

        if (tokens.size() != 2)
            throw Error(
                this->_file, line.first, ERR_COMPONENT_DECLARATION_FORMAT);

        const auto& components = this->_circuit.getComponents();

        if (components.count(tokens[1]))
            throw Error(this->_file, line.first, ERR_COMPONENT_ALREADY_EXISTS);

        auto component = nts::Factory::Create(tokens[0]);

        this->_circuit.addComponent(tokens[1], component);
    }
}

void parser::Parser::linkComponents()
{
    bool section = false;

    for (const auto& line : this->_lines) {
        if (line.second == LINKS_LABEL) {
            section = true;
            continue;
        }

        if (!section) continue;

        std::vector<std::string> tokens = split(line.second, ' ');

        if (tokens.size() != 2)
            throw Error(this->_file, line.first, ERR_COMPONENT_LINK_FORMAT);

        std::vector<std::string> link1 = split(tokens[0], ':');
        std::vector<std::string> link2 = split(tokens[1], ':');

        if (link1.size() != 2)
            throw Error(this->_file, line.first, ERR_COMPONENT_LINK_FORMAT);
        if (link2.size() != 2)
            throw Error(this->_file, line.first, ERR_COMPONENT_LINK_FORMAT);

        const auto& components = this->_circuit.getComponents();

        if (components.count(link1[0]) == 0)
            throw Error(this->_file, line.first, ERR_COMPONENT_DOESNT_EXISTS);
        if (components.count(link2[0]) == 0)
            throw Error(this->_file, line.first, ERR_COMPONENT_DOESNT_EXISTS);

        if (!isNumber(link1[1]))
            throw Error(this->_file, line.first, ERR_PIN_NOT_A_NUMBER);
        if (!isNumber(link2[1]))
            throw Error(this->_file, line.first, ERR_PIN_NOT_A_NUMBER);

        int link1Pin = std::stoi(link1[1]);
        int link2Pin = std::stoi(link2[1]);

        if (components.at(link1[0])->getOUTs().count(link1Pin) == 0)
            throw Error(this->_file, line.first, ERR_PIN_NOT_AN_OUT);

        if (components.at(link2[0])->getINs().count(link2Pin) == 0)
            throw Error(this->_file, line.first, ERR_PIN_NOT_AN_IN);

        components.at(link2[0])->setLink(
            link2Pin, *components.at(link1[0]), link1Pin);
    }
}
