/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output.cpp
*/

#include "Output.hpp"

#include "nts/Error.hpp"

io::Output::Output() : AComponent("Output", {1}, {})
{
}

nts::Tristate io::Output::compute(std::size_t pin)
{
    if (this->getINs().count(pin) == 0)
        throw nts::Error(this->getType(), "Pin doesn't exist");

    const auto& states = this->getStates();

    if (states.count(pin) == 0) {
        const nts::Link::pointer link = this->getLink(pin);

        if (link == nullptr)
            throw nts::Error(this->getType(), "Pin isn't linked");

        this->setState(pin, nts::UNDEFINED);
        this->setState(pin, link->getOther()->compute(link->getOtherPin()));
    }

    return states.at(pin);
}
