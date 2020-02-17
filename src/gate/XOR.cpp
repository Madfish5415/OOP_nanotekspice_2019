/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** XOR.cpp
*/

#include "XOR.hpp"
nts::Tristate gate::XOR::operate(nts::Tristate t1, nts::Tristate t2)
{
    if ((t1 == nts::TRUE && t2 == nts::FALSE) || (t1 == nts::FALSE && t2 == nts::TRUE)) return nts::TRUE;
    if ((t1 == nts::TRUE && t2 == nts::TRUE) || (t1 == nts::FALSE && t2 == nts::FALSE)) return nts::FALSE;

    return nts::UNDEFINED;
}
