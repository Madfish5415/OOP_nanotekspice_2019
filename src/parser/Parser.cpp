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
#include <nts/Error.hpp>
#include <nts/Factory.hpp>
#include <sstream>

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
    bool chipsetsLabel = false, linksLabel = false;
    int state = 0;

    for (const auto& line : this->_lines) {
        if (line.second == ".chipsets:") {
            if (chipsetsLabel)
                throw nts::Error("Parser", "Duplicate chipsets labels");

            chipsetsLabel = true;
        }

        if (line.second == ".links:") {
            if (!chipsetsLabel)
                throw nts::Error("Parser", "Links label before chipset label");
            if (linksLabel)
                throw nts::Error("Parser", "Duplicate links labels");

            linksLabel = true;
        }
    }

    if (!chipsetsLabel) throw nts::Error("Parser", "No chipsets label");
    if (!linksLabel) throw nts::Error("Parser", "No links label");

    for (const auto& line : this->_lines) {
        if (line.second == ".chipsets:") {
            state = 1;
        } else if (line.second == ".links:") {
            state = 2;
        } else {
            std::cout << line.second << std::endl;

            std::vector<std::string> tokens = split(line.second, ' ');

            if (tokens.size() != 2)
                throw nts::Error(
                    "Parser", "Invalid component declaration format");

            if (state == 1) {
                auto component = nts::Factory::Create(tokens[0]);

                this->_circuit.addComponent(tokens[1], component);
            } else if (state == 2) {
                std::vector<std::string> link1 = split(tokens[0], ':');
                std::vector<std::string> link2 = split(tokens[1], ':');

                if (link1.size() != 2)
                    throw nts::Error("Parser", "Invalid link format");
                if (link2.size() != 2)
                    throw nts::Error("Parser", "Invalid link format");

                const auto& components = this->_circuit.getComponents();

                if (components.count(link1[0]) == 0)
                    throw nts::Error(
                        "Parser", "Invalid link component (doesn't exists)");
                if (components.count(link2[0]) == 0)
                    throw nts::Error(
                        "Parser", "Invalid link component (doesn't exists)");

                if (!isNumber(link1[1]))
                    throw nts::Error(
                        "Parser", "Invalid link pin (not a number)");
                if (!isNumber(link2[1]))
                    throw nts::Error(
                        "Parser", "Invalid link pin (not a number)");

                int link1Pin = std::stoi(link1[1]);
                int link2Pin = std::stoi(link2[1]);

                if (components.at(link1[0])->getOUTs().count(link1Pin) == 0)
                    throw nts::Error(
                        "Parser", "Invalid link pin (not a OUT pin)");

                if (components.at(link2[0])->getINs().count(link2Pin) == 0)
                    throw nts::Error(
                        "Parser", "Invalid link pin (not a IN pin)");

                components.at(link2[0])->setLink(
                    link2Pin, *components.at(link1[0]), link1Pin);
            }
        }
    }
}
