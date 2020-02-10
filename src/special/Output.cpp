/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output.cpp
*/

#include "Output.hpp"

special::Output::Output() : SpecialComponent(nts::UNDEFINED)
{
}

nts::Tristate special::Output::compute(std::size_t pin)
{
    if (pin != 1) throw std::exception();  // TODO: Unknown pin

    if (this->_links.find(pin) == this->_links.end())
        throw std::exception();  // TODO: One or several outputs are not linked

    this->_state = AComponent::compute(pin);

    return SpecialComponent::compute(pin);
}
