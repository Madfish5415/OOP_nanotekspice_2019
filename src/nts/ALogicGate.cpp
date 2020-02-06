/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** ALogicGate.cpp
*/

#include "ALogicGate.hpp"

nts::Tristate nts::ALogicGate::compute(std::size_t)
{
    nts::Tristate state = nts::UNDEFINED, current;
    auto it = this->_links.begin();

    for (int i = 0; it != this->_links.end(); ++i, ++it) {
        current = AComponent::compute(it->first);

        if (i == 0) state = current;
        state = this->operate(state, current);
    }

    return state;
}
