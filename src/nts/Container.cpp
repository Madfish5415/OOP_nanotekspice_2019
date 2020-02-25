/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Container.cpp
*/

#include "Container.hpp"

#include <iostream>

#include "Error.hpp"

nts::Container::Container(const std::string& type, const std::set<size_t>& INs,
    const std::set<size_t>& OUTs)
    : AComponent(type, INs, OUTs)
{
    for (const auto& out : this->getOUTs()) this->addPin(out);
}

nts::Tristate nts::Container::compute(std::size_t pin)
{
    const auto& states = this->getStates();

    if (states.count(pin) == 0) {
        const Link::pointer link = this->getLink(pin);

        if (link == nullptr)
            throw Error(this->getType(), "Pin isn't linked");

        this->setState(pin, nts::UNDEFINED);
        this->setState(pin, link->getOther()->compute(link->getOtherPin()));
    }

    return states.at(pin);
}

void nts::Container::dump()
{
    AComponent::dump();

    if (!this->_components.empty()) {
        std::cout << "Components:" << std::endl;
        for (const auto& component : _components) component.second->dump();
    }
}

void nts::Container::reset()
{
    AComponent::reset();

    for (const auto& component : _components) component.second->reset();
}

void nts::Container::addComponent(
    const std::string& name, IComponent::pointer& component)
{
    if (this->_components.count(name))
        throw Error(this->getType(), "Component already exists");

    this->_components[name] = std::move(component);
}

const nts::Container::Components& nts::Container::getComponents() const
{
    return this->_components;
}
