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

nts::ALogicGate::ALogicGate(const nts::ALogicGate& logicGate) : ALogicGate()
{
    this->_value = logicGate._value;
    this->_links = logicGate._links;
}

nts::ALogicGate& nts::ALogicGate::operator=(const nts::ALogicGate& logicGate)
{
    if (this == &logicGate) return *this;

    this->_value = logicGate._value;
    this->_links = logicGate._links;

    return *this;
}
