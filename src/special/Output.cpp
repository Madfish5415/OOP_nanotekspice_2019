/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output.cpp
*/

#include "Output.hpp"

nts::Tristate special::Output::compute(std::size_t pin)
{
    if (this->_links.find(pin) == this->_links.end())
        throw std::exception();  // TODO: One or several outputs are not linked

    return AComponent::compute(pin);
}
