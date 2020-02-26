/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Error.cpp
*/

#include "Error.hpp"

parser::Error::Error(const std::string& error)
{
    this->_message = "Parser: " + error;
}

const char* parser::Error::what() const noexcept
{
    return this->_message.c_str();
}

parser::ErrorAtLine::ErrorAtLine(
    const std::string& path, std::size_t line, const std::string& error)
{
    this->_message =
        "Parser: " + path + ":" + std::to_string(line) + ": " + error;
}

const char* parser::ErrorAtLine::what() const noexcept
{
    return this->_message.c_str();
}
