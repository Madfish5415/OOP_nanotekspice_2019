/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock.cpp
*/

#include "Clock.hpp"

#include <algorithm>

#include "nts/Error.hpp"

io::Clock::Clock() : AComponent("Clock", {}, {1})
{
}

nts::Tristate io::Clock::compute(std::size_t pin)
{
    if (this->getOUTs().count(pin) == 0)
        throw nts::Error(this->getType(), "Pin doesn't exist");

    const std::string& value = this->getValue();

    if (value == "0") return nts::FALSE;
    if (value == "1") return nts::TRUE;
    return nts::UNDEFINED;
}
