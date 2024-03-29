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
#include <utility>
#include <vector>

#include "Error.hpp"
#include "nts/Factory.hpp"
#include "util/string.hpp"

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

static bool isNumber(const std::string& string)
{
    for (const auto& c : string)
        if (!isdigit(c)) return false;

    return true;
}

parser::Parser::Parser(std::string path) : _path(std::move(path))
{
    this->fill();
    this->clean();
}

nts::Circuit& parser::Parser::parse()
{
    this->checkLabels();
    this->addComponents();
    this->linkComponents();

    return this->_circuit;
}

void parser::Parser::fill()
{
    std::ifstream file(this->_path);

    if (file.fail()) throw Error(ERR_FILE_FAILED);

    std::string line;

    for (std::size_t i = 1; std::getline(file, line); ++i)
        this->_lines[i] = line;
}

void parser::Parser::clean()
{
    for (auto it = this->_lines.begin(); it != this->_lines.end();) {
        comment(it->second);
        spaces(it->second);
        util::string::trim(it->second);

        if (it->second.empty())
            it = this->_lines.erase(it);
        else
            ++it;
    }
}

void parser::Parser::checkLabels()
{
    bool chipsetsLabel = false, linksLabel = false;

    for (const auto& line : this->_lines) {
        if (line.second == CHIPSETS_LABEL) {
            if (chipsetsLabel)
                throw ErrorAtLine(
                    this->_path, line.first, ERR_DUPLICATE_CHIPSETS_LABEL);

            chipsetsLabel = true;
        }

        if (line.second == LINKS_LABEL) {
            if (linksLabel)
                throw ErrorAtLine(
                    this->_path, line.first, ERR_DUPLICATE_LINKS_LABEL);
            if (!chipsetsLabel)
                throw ErrorAtLine(
                    this->_path, line.first, ERR_LINKS_BEFORE_CHIPSETS);

            linksLabel = true;
        }
    }

    if (!chipsetsLabel) throw Error(ERR_NO_CHIPSETS_LABEL);
    if (!linksLabel) throw Error(ERR_NO_LINKS_LABEL);
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

        std::vector<std::string> tokens = util::string::split(line.second, ' ');

        if (tokens.size() != 2)
            throw ErrorAtLine(
                this->_path, line.first, ERR_COMPONENT_DECLARATION_FORMAT);

        const auto& components = this->_circuit.getComponents();

        if (components.count(tokens[1]))
            throw ErrorAtLine(
                this->_path, line.first, ERR_COMPONENT_ALREADY_EXISTS);

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

        std::vector<std::string> tokens = util::string::split(line.second, ' ');

        if (tokens.size() != 2)
            throw ErrorAtLine(
                this->_path, line.first, ERR_COMPONENT_LINK_FORMAT);

        std::vector<std::string> link1 = util::string::split(tokens[0], ':');
        std::vector<std::string> link2 = util::string::split(tokens[1], ':');

        if (link1.size() != 2)
            throw ErrorAtLine(
                this->_path, line.first, ERR_COMPONENT_LINK_FORMAT);
        if (link2.size() != 2)
            throw ErrorAtLine(
                this->_path, line.first, ERR_COMPONENT_LINK_FORMAT);

        const auto& components = this->_circuit.getComponents();

        if (components.count(link1[0]) == 0)
            throw ErrorAtLine(
                this->_path, line.first, ERR_COMPONENT_DOESNT_EXIST);
        if (components.count(link2[0]) == 0)
            throw ErrorAtLine(
                this->_path, line.first, ERR_COMPONENT_DOESNT_EXIST);

        if (!isNumber(link1[1]))
            throw ErrorAtLine(this->_path, line.first, ERR_PIN_NOT_A_NUMBER);
        if (!isNumber(link2[1]))
            throw ErrorAtLine(this->_path, line.first, ERR_PIN_NOT_A_NUMBER);

        int link1Pin = std::stoi(link1[1]);
        int link2Pin = std::stoi(link2[1]);

        std::pair<std::string, int> src, dest;

        if (components.at(link1[0])->getINs().count(link1Pin))
            src = {link1[0], link1Pin};
        else if (components.at(link1[0])->getOUTs().count(link1Pin))
            dest = {link1[0], link1Pin};
        else
            throw ErrorAtLine(this->_path, line.first, ERR_PIN_DOESNT_EXIST);

        if (components.at(link2[0])->getINs().count(link2Pin)) {
            if (!src.first.empty())
                throw ErrorAtLine(
                    this->_path, line.first, ERR_PIN_CANT_LINK_IN);

            src = {link2[0], link2Pin};
        } else if (components.at(link2[0])->getOUTs().count(link2Pin)) {
            if (!dest.first.empty())
                throw ErrorAtLine(
                    this->_path, line.first, ERR_PIN_CANT_LINK_OUT);

            dest = {link2[0], link2Pin};
        } else
            throw ErrorAtLine(this->_path, line.first, ERR_PIN_DOESNT_EXIST);

        components.at(src.first)->setLink(
            src.second, *components.at(dest.first), dest.second);
    }
}
