/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SpecialComponent.cpp
*/

#include "SpecialComponent.hpp"

nts::SpecialComponent::SpecialComponent(nts::Tristate state) : _state(state)
{
}

nts::SpecialComponent::SpecialComponent(
    const nts::SpecialComponent& specialComponent) : SpecialComponent()
{
    this->_value = specialComponent._value;
    this->_links = specialComponent._links;
    this->_state = specialComponent._state;
}

nts::SpecialComponent& nts::SpecialComponent::operator=(
    const nts::SpecialComponent& specialComponent)
{
    if (this == &specialComponent) return *this;

    this->_value = specialComponent._value;
    this->_links = specialComponent._links;
    this->_state = specialComponent._state;

    return *this;
}

nts::Tristate nts::SpecialComponent::compute(std::size_t pin)
{
    if (pin != 1) throw std::exception();  // TODO: Unknown pin

    return this->_state;
}

nts::IComponent* nts::SpecialComponent::clone()
{
    return new SpecialComponent(*this);
}
