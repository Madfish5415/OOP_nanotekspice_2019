/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Undefined.cpp
*/

#include "Undefined.hpp"

#include "nts/Error.hpp"

io::mock::Undefined::Undefined() : AComponent("Undefined", {}, {1})
{
}

nts::Tristate io::mock::Undefined::compute(std::size_t pin)
{
    if (this->getOUTs().count(pin) == 0)
        throw nts::Error(this->getType(), "Pin doesn't exist");

    return nts::UNDEFINED;
}
