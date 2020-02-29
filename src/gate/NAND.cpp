/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NAND.cpp
*/

#include "NAND.hpp"

gate::NAND::NAND(const std::set<size_t>& INs, const std::set<size_t>& OUTs)
    : AND(INs, OUTs)
{
}

nts::Tristate gate::NAND::compute(std::size_t pin)
{
    nts::Tristate result = AND::compute(pin);

    if (result == nts::TRUE) result = nts::FALSE;
    if (result == nts::FALSE) result = nts::TRUE;

    return result;
}
