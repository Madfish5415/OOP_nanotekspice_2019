/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False.cpp
*/

#include "False.hpp"

io::False::False() : AComponent("False", {}, {1})
{
}

nts::Tristate io::False::compute(std::size_t pin)
{
    if (this->getOUTs().count(pin) == 0)
        throw std::exception();  // TODO: Custom error class

    return nts::FALSE;
}
