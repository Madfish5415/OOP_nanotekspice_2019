/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Error.cpp
*/

#include "Error.hpp"

nts::Error::Error(const std::string& component, const std::string& error)
{
    this->_message = component + ": " + error;
}

const char* nts::Error::what() const noexcept
{
    return this->_message.c_str();
}
