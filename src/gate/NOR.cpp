/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NOR.cpp
*/

#include "NOR.hpp"

gate::NOR::NOR(const std::set<size_t>& INs, const std::set<size_t>& OUTs)
    : OR(INs, OUTs)
{
}

nts::Tristate gate::NOR::compute(std::size_t pin)
{
    nts::Tristate result = OR::compute(pin);

    if (result == nts::TRUE) result = nts::FALSE;
    if (result == nts::FALSE) result = nts::TRUE;

    return result;
}
