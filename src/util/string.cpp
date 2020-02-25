/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** string.cpp
*/

#include <algorithm>
#include <sstream>

#include "string.hpp"

std::vector<std::string> util::string::split(const std::string& string, char delim)
{
    std::istringstream stream(string);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(stream, token, delim)) tokens.push_back(token);

    return tokens;
}

void util::string::trim(std::string& string)
{
    if (string.empty()) return;

    std::string::iterator left = std::find_if(
        string.begin(), string.end(), [](char c) { return !isspace(c); });

    string.erase(string.begin(), left);

    std::string::reverse_iterator right = std::find_if(
        string.rbegin(), string.rend(), [](char c) { return !isspace(c); });

    string.erase(right.base(), string.end());
}