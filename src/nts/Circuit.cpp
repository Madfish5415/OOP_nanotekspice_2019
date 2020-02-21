/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit.cpp
*/

#include "Circuit.hpp"

#include <algorithm>
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
    const auto& components = this->getComponents();

    if (components.count(name) == 0)
        throw std::exception();  // TODO: Custom error class
    if (components.at(name)->getType() != "Input")
        throw std::exception();  // TODO: Custom error class

    components.at(name)->setValue(value);
}

void nts::Circuit::simulate()
{
    const auto& components = this->getComponents();

    for (const auto& component : components)
        if (component.second->getType() == "Output")
            this->_results[component.first] = component.second->compute(1);

    for (const auto& component : components) {
        if (component.second->getType() == "Clock") {
            std::string value = component.second->getValue();

            if (value == "0")
                value = "1";
            else if (value == "1")
                value = "0";

            component.second->setValue(value);
        }
    }
}
