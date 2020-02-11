/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AND.cpp
*/

#include "AND.hpp"

nts::Tristate gate::AND::operate(nts::Tristate t1, nts::Tristate t2)
{
    if ((t1 == nts::TRUE) && (t2 == nts::TRUE)) return nts::TRUE;
    if ((t1 == nts::FALSE) || (t2 == nts::FALSE)) return nts::FALSE;

    return nts::UNDEFINED;
}
