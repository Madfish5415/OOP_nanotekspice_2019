/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit.cpp
*/

#include "Circuit.hpp"

#include <iostream>

nts::Circuit::Circuit() : Container("Circuit", {}, {})
{
}

void nts::Circuit::display()
{
    for (const auto& result : _results) {
        std::cout << result.first << "=";

        switch (result.second) {
            case UNDEFINED:
                std::cout << "U";
                break;
            case FALSE:
                std::cout << "0";
                break;
            case TRUE:
                std::cout << "1";
                break;
        }

        std::cout << std::endl;
    }
}

void nts::Circuit::input(const std::string& name, const std::string& value)
{
    auto inputs = this->filterComponents("Input");

    if (inputs.count(name) == 0)
        throw std::exception();  // TODO: Custom error class

    inputs[name]->setValue(value);
}

void nts::Circuit::simulate()
{
    auto outputs = this->filterComponents("Output");

    for (const auto& output : outputs)
        this->_results[output.first] = output.second->compute(1);

    auto clocks = this->filterComponents("Clock");

    for (const auto& clock : clocks) {
        std::string value = clock.second->getValue();

        if (value == "0")
            value = "1";
        else if (value == "1")
            value = "0";

        clock.second->setValue(value);
    }
}

std::map<std::string, nts::IComponent*> nts::Circuit::filterComponents(
    const std::string& type) const
{
    auto components = this->getComponents();
    std::map<std::string, IComponent*> filtered;

    for (const auto& component : components)
        if (component.second->getType() == type)
            filtered[component.first] = component.second;

    return filtered;
}
