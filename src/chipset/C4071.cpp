/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4071.cpp
*/

#include "C4071.hpp"

#include "../gate/OR.hpp"

chipset::C4071::C4071() : AChipset()
{
    this->addLogicGate({1, 2}, {3}, *(new gate::OR()));
}
