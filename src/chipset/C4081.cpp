/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4081.cpp
*/

#include "C4081.hpp"

#include "../gate/AND.hpp"

chipset::C4081::C4081()
{
    this->addLogicGate({1, 2}, {3}, *(new gate::AND()));
    this->addLogicGate({5, 6}, {4}, *(new gate::AND()));
    this->addLogicGate({8, 9}, {10}, *(new gate::AND()));
    this->addLogicGate({12, 13}, {11}, *(new gate::AND()));
}
