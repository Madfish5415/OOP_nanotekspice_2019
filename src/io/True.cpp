/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True.cpp
*/

#include "True.hpp"

#include "nts/Error.hpp"

io::True::True() : AComponent("True", {}, {1})
{
}

nts::Tristate io::True::compute(std::size_t pin)
{
    if (this->getOUTs().count(pin) == 0)
        throw nts::Error(this->getType(), "Pin doesn't exist");

    return nts::TRUE;
}
