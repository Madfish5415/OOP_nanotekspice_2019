/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory.cpp
*/

#include "Factory.hpp"

#include "Error.hpp"

nts::IComponent::pointer nts::Factory::Create(
    const std::string& type, const std::string& value)
{
    if (constructors().count(type) == 0)
        throw Error("Factory", "Component isn't registered");

    return (constructors()[type])(value);
}

void nts::Factory::Register(
    const std::string& type, const nts::Constructor& constructor)
{
    if (constructors().count(type))
        throw Error("Factory", "Component already registered");

    constructors()[type] = constructor;
}

std::map<std::string, nts::Constructor>& nts::Factory::constructors()
{
    static std::map<std::string, nts::Constructor> constructors;

    return constructors;
}
