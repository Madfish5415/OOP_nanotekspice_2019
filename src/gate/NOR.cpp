/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NOR.cpp
*/

#include "NOR.hpp"

nts::Tristate gate::NOR::operate(nts::Tristate t1, nts::Tristate t2)
{
    nts::Tristate result = OR::operate(t1, t2);

    if (result == nts::TRUE) return nts::FALSE;
    if (result == nts::FALSE) return nts::TRUE;

    return nts::UNDEFINED;
}
