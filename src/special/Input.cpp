/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input.cpp
*/

#include "Input.hpp"

nts::Tristate special::Input::compute(std::size_t)
{
    return this->_state;
}

void special::Input::setState(nts::Tristate state)
{
    this->_state = state;
}
