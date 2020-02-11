/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

#include <algorithm>

nts::AComponent::AComponent(const nts::AComponent& component)
{
    this->_value = component._value;
    this->_links = component._links;
}

nts::AComponent::AComponent(const std::string& value) : _value(value)
{
}

nts::AComponent& nts::AComponent::operator=(const nts::AComponent& component)
{
    if (this == &component)
        return *this;

    this->_value = component._value;
    this->_links = component._links;

    return *this;
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    if (!this->_links[pin].first) return nts::UNDEFINED;

    return this->_links[pin].first->compute(this->_links[pin].second);
}

void nts::AComponent::setLink(
    std::size_t pin, nts::IComponent& other, std::size_t otherPin)
{
    if (this->_links.find(pin) != this->_links.end())
        throw std::exception();  // TODO: Already linked

    this->_links[pin] = {&other, otherPin};
}

void nts::AComponent::dump() const
{
    // TODO: Dump method
}

nts::IComponent* nts::AComponent::clone()
{
    return new AComponent(*this);
}
