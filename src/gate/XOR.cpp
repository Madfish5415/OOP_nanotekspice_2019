/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** XOR.cpp
*/

#include "XOR.hpp"

static nts::Tristate operate(const nts::Tristate t1, const nts::Tristate t2)
{
    if (((t1 == nts::TRUE) && (t2 == nts::FALSE)) ||
        ((t1 == nts::FALSE) && (t2 == nts::TRUE)))
        return nts::TRUE;
    if (((t1 == nts::TRUE) && (t2 == nts::TRUE)) ||
        ((t1 == nts::FALSE) && (t2 == nts::FALSE)))
        return nts::FALSE;

    return nts::UNDEFINED;
}

gate::XOR::XOR(const std::set<size_t>& INs, const std::set<size_t>& OUTs)
    : AComponent("XOR", INs, OUTs)
{
}

nts::Tristate gate::XOR::compute(std::size_t pin)
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

        if (i == 0)
            result = value;
        else
            result = operate(result, value);
    }

    return result;
}
