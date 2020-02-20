/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Container.cpp
*/

#include "Container.hpp"

nts::Container::Container(const std::string& type, const std::set<size_t>& INs,
    const std::set<size_t>& OUTs)
    : AComponent(type, INs, OUTs)
{
}

nts::Tristate nts::Container::compute(std::size_t pin)
{
    if (this->getOUTs().count(pin) == 0)
        throw std::exception();  // TODO: Custom error class

    if (this->_states.count(pin) == 0) {
        const Link& link = this->getLink(pin);

        if (link.other == nullptr)
            throw std::exception();  // TODO: Custom class error

        this->_states[pin] = link.other->compute(link.otherPin);
    }

    return this->_states[pin];
}

void nts::Container::dump()
{
    AComponent::dump();

    for (const auto& component : _components) component.second->dump();
}

void nts::Container::reset()
{
    AComponent::reset();

    for (const auto& component : _components) component.second->reset();
}

void nts::Container::addComponent(
    const std::string& name, nts::IComponent& component)
{
    if (this->_components.count(name))
        throw std::exception();  // TODO: Custom class error

    this->_components[name] = &component;
}

const std::map<std::string, nts::IComponent*>& nts::Container::getComponents()
    const
{
    return this->_components;
}

void nts::Container::removeComponent(const std::string& name)
{
    if (this->_components.count(name) == 0)
        throw std::exception();  // TODO: Custom class error

    delete this->_components[name];

    this->_components.erase(name);
}
