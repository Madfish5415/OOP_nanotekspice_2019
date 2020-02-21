/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True.cpp
*/

#include "True.hpp"

io::True::True() : AComponent("True", {}, {1})
{
}

nts::Tristate io::True::compute(std::size_t pin)
{
    if (this->getOUTs().count(pin) == 0)
        throw std::exception();  // TODO: Custom error class

    return nts::TRUE;
}
