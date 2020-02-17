/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NAND.cpp
*/

#include "NAND.hpp"

nts::Tristate gate::NAND::operate(nts::Tristate t1, nts::Tristate t2)
{
    nts::Tristate result = AND::operate(t1, t2);

    if (result == nts::TRUE) return nts::FALSE;
    if (result == nts::FALSE) return nts::TRUE;

    return nts::UNDEFINED;
}
