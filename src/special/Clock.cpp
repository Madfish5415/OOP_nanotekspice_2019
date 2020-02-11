/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock.cpp
*/

#include "Clock.hpp"

special::Clock::Clock(nts::Tristate state) : SpecialComponent(state)
{
}

nts::Tristate special::Clock::compute(std::size_t pin)
{
    if (pin != 1) throw std::exception();  // TODO: Unknown pin

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

    return SpecialComponent::compute(pin);
}
