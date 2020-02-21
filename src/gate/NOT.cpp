/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NOT.cpp
*/

#include "NOT.hpp"

static nts::Tristate operate(const nts::Tristate t)
{
    if (t == nts::TRUE) return nts::FALSE;
    if (t == nts::FALSE) return nts::TRUE;

    return nts::UNDEFINED;
}

gate::NOT::NOT(const std::set<size_t>& INs, const std::set<size_t>& OUTs)
    : AComponent("NOT", INs, OUTs)
{
}

nts::Tristate gate::NOT::compute(std::size_t pin)
{
    if (this->getOUTs().count(pin) == 0)
        throw std::exception();  // TODO: Custom error class

    const auto& ins = this->getINs();
    auto it = ins.begin();
    const auto& states = this->getStates();
    nts::Tristate result = nts::UNDEFINED;

    for (std::size_t i = 0; it != ins.end(); ++i, ++it) {
        if (states.count(*it) == 0) {
            const nts::Link::pointer link = this->getLink(*it);

            this->setState(*it, nts::UNDEFINED);
            this->setState(*it, link->getOther()->compute(link->getOtherPin()));
        }

        const nts::Tristate value = states.at(*it);

        result = operate(value);
    }

    return result;
}
