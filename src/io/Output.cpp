/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output.cpp
*/

#include "Output.hpp"

io::Output::Output() : AComponent("Output", {1}, {})
{
}

nts::Tristate io::Output::compute(std::size_t pin)
{
    if (this->getINs().count(pin) == 0)
        throw std::exception();  // TODO: Custom error class

    const auto& states = this->getStates();

    if (states.count(pin) == 0) {
        const nts::Link::pointer link = this->getLink(pin);

        if (link == nullptr)
            throw std::exception();  // TODO: Custom class error

        this->setState(pin, nts::UNDEFINED);
        this->setState(pin, link->getOther()->compute(link->getOtherPin()));
    }

    return states.at(pin);
}
