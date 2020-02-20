/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory.cpp
*/

#include "Factory.hpp"

std::unique_ptr<nts::IComponent> nts::Factory::Create(
    const std::string& type, const std::string& value)
{
    if (constructors().count(type) == 0)
        throw std::exception();  // TODO: Custom error class

    return (constructors()[type])(value);
}

void nts::Factory::Register(
    const std::string& type, const nts::Constructor& constructor)
{
    if (constructors().count(type))
        throw std::exception();  // TODO: Custom error class

    constructors()[type] = constructor;
}

std::map<std::string, nts::Constructor>& nts::Factory::constructors()
{
    static std::map<std::string, nts::Constructor> constructors;

    return constructors;
}
