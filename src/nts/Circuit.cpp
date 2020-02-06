/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit.cpp
*/

#include "Circuit.hpp"

#include <iostream>

#include "../special/Output.hpp"

void nts::Circuit::addComponent(
    const std::string& name, nts::IComponent& component)
{
    if (this->_components.find(name) != this->_components.end())
        throw std::exception();  // TODO: Several components share the same name

    this->_components[name] = &component;
}

void nts::Circuit::removeComponent(const std::string& name)
{
    this->_components.erase(name);
}

nts::IComponent& nts::Circuit::getComponent(const std::string& name)
{
    if (this->_components.find(name) == this->_components.end())
        throw std::exception();  // TODO: A component name is unknown

    return *this->_components[name];
}

void nts::Circuit::display()
{
    for (const auto& result : _results) {
        std::cout << result.first << "=";

        switch (result.second) {
            case UNDEFINED:
                std::cout << "U";
                break;
            case TRUE:
                std::cout << "1";
                break;
            case FALSE:
                std::cout << "0";
                break;
        }

        std::cout << std::endl;
    }
}

void nts::Circuit::simulate()
{
    for (const auto& component : _components)
        if (dynamic_cast<special::Output*>(component.second))
            this->_results[component.first] = component.second->compute(1);
}
