/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** string.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_STRING_HPP
#define OOP_NANOTEKSPICE_2019_STRING_HPP

#include <string>
#include <vector>

namespace util {

namespace string {

std::vector<std::string> split(const std::string& string, char delim);
void trim(std::string& string);

}

}

#endif  // OOP_NANOTEKSPICE_2019_STRING_HPP
