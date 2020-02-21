/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input.cpp
*/

#include "Input.hpp"

io::Input::Input() : AComponent("Input", {}, {1})
{
}

nts::Tristate io::Input::compute(std::size_t pin)
{
    if (this->getOUTs().count(pin) == 0)
        throw std::exception();  // TODO: Custom error class

    const std::string& value = this->getValue();

    if (value == "0") return nts::FALSE;
    if (value == "1") return nts::TRUE;
    return nts::UNDEFINED;
}
