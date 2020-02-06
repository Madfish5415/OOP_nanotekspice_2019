/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock.cpp
*/

#include "Clock.hpp"

nts::Tristate special::Clock::compute(std::size_t)
{
    nts::Tristate state = this->_state;

    switch (this->_state) {
        case nts::UNDEFINED:
            break;
        case nts::TRUE:
            this->_state = nts::FALSE;
            break;
        case nts::FALSE:
            this->_state = nts::TRUE;
            break;
    }

    return state;
}

void special::Clock::setState(nts::Tristate state)
{
    this->_state = state;
}
