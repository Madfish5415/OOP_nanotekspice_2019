/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

#include <algorithm>
#include <iostream>

nts::AComponent::AComponent(const std::string& type,
    const std::set<size_t>& INs, const std::set<size_t>& OUTs)
    : _type(type)
{
    this->_INs = INs;
    this->_OUTs = OUTs;

    for (const auto& in : this->_INs) this->_pins[in] = nullptr;
}

void nts::AComponent::dump()
{
    std::cout << "Type: " << this->getType() << std::endl;
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

const nts::Link* nts::AComponent::getLink(std::size_t pin) const
{
    if (this->_pins.count(pin) == 0)
        throw std::exception();  // TODO: Custom error class

    return this->_pins.at(pin);
}

void nts::AComponent::setLink(
    std::size_t pin, IComponent& other, size_t otherPin)
{
    if (this->getLink(pin) != nullptr)
        throw std::exception();  // TODO: Custom error class

    this->_pins[pin] = new Link(&other, otherPin);
}

const std::string& nts::AComponent::getValue() const
{
    return this->_value;
}

void nts::AComponent::setValue(const std::string& value)
{
    this->_value = value;
}

void nts::AComponent::addPin(size_t pin, nts::Link* link)
{
    if (this->_pins.count(pin))
        throw std::exception();  // TODO: Custom class error

    this->_pins[pin] = link;
}

void nts::AComponent::setState(size_t pin, nts::Tristate state)
{
    this->_states[pin] = state;
}

const std::map<std::size_t, nts::Tristate>& nts::AComponent::getStates() const
{
    return this->_states;
}
