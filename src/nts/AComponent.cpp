/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

#include "Error.hpp"

nts::AComponent::AComponent(
    std::string type, const std::set<size_t>& INs, const std::set<size_t>& OUTs)
    : _type(std::move(type))
{
    this->_INs = INs;
    this->_OUTs = OUTs;

    for (const auto& in : this->_INs) this->_pins[in] = nullptr;
}

void nts::AComponent::dump()
{
    std::cout << "Type: " << this->getType() << std::endl;

    if (!this->_INs.empty()) {
        std::cout << "INs:";
        for (const auto& in : this->_INs) std::cout << " " << in;
        std::cout << std::endl;
    }

    if (!this->_OUTs.empty()) {
        std::cout << "OUTs:";
        for (const auto& out : this->_OUTs) std::cout << " " << out;
        std::cout << std::endl;
    }
}

void nts::AComponent::reset()
{
    this->_states.clear();
}

const std::string& nts::AComponent::getType() const
{
    return this->_type;
}

const std::set<std::size_t>& nts::AComponent::getINs() const
{
    return this->_INs;
}

const std::set<std::size_t>& nts::AComponent::getOUTs() const
{
    return this->_OUTs;
}

nts::Link::pointer nts::AComponent::getLink(std::size_t pin) const
{
    if (this->_pins.count(pin) == 0)
        throw Error(this->getType(), "Pin doesn't exist");

    return this->_pins.at(pin);
}

void nts::AComponent::setLink(
    std::size_t pin, IComponent& other, size_t otherPin)
{
    if (this->getLink(pin) != nullptr)
        throw Error(this->getType(), "Pin already linked");

    this->_pins[pin] = std::make_shared<Link>(&other, otherPin);
}

const std::string& nts::AComponent::getValue() const
{
    return this->_value;
}

void nts::AComponent::setValue(const std::string& value)
{
    this->_value = value;
}

void nts::AComponent::addPin(size_t pin)
{
    if (this->_pins.count(pin))
        throw Error(this->getType(), "Pin already exist");

    this->_pins[pin] = nullptr;
}

void nts::AComponent::setState(size_t pin, nts::Tristate state)
{
    this->_states[pin] = state;
}

const std::map<std::size_t, nts::Tristate>& nts::AComponent::getStates() const
{
    return this->_states;
}
