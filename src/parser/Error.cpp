/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Error.cpp
*/

#include "Error.hpp"

parser::Error::Error(
    const std::string& file, std::size_t line, const std::string& message)
    : nts::Error("Parser")
{
    this->_message += file;

    if (line) this->_message += ":" + std::to_string(line);

    this->_message += ": " + message;
}
