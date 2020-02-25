/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Error.cpp
*/

#include "Error.hpp"

cli::Error::Error(const std::string& error)
{
    this->_message = "CLI: " + error;
}

const char* cli::Error::what() const noexcept
{
    return this->_message.c_str();
}

cli::ErrorRuntime::ErrorRuntime(
    const std::string& command, const std::string& error)
{
    this->_message = "CLI: " + command + ": " + error;
}

const char* cli::ErrorRuntime::what() const noexcept
{
    return this->_message.c_str();
}
