/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NOT.cpp
*/

#include "NOT.hpp"

nts::Tristate gate::NOT::operate(nts::Tristate t1, nts::Tristate t2)
{
    (void) t2;

    if (t1 == nts::TRUE) return nts::FALSE;
    if (t1 == nts::FALSE) return nts::TRUE;

    return nts::UNDEFINED;
}
