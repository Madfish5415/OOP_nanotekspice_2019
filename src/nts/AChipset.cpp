/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AChipset.cpp
*/

#include "AChipset.hpp"

nts::AChipset::AChipset(const std::string& value) : AComponent(value)
{
}

nts::AChipset::AChipset(const nts::AChipset& chipset) : AChipset()
{
    this->_value = chipset._value;
    this->_links = chipset._links;

    for (const auto& logicGate : chipset._logicGates)
        this->_logicGates[logicGate.first] = logicGate.second->clone();
}

nts::AChipset::~AChipset()
{
    for (const auto& logicGate : _logicGates) delete logicGate.second;
}

nts::AChipset& nts::AChipset::operator=(const nts::AChipset& chipset)
{
    if (this == &chipset) return *this;

    this->_value = chipset._value;
    this->_links = chipset._links;

    for (const auto& logicGate : chipset._logicGates)
        this->_logicGates[logicGate.first] = logicGate.second->clone();

    return *this;
}

nts::IComponent* nts::AChipset::clone()
{
    return new AChipset(*this);
}

void nts::AChipset::addLogicGate(const std::vector<size_t>& inPins,
    const std::vector<size_t>& outPins, IComponent& logicGate)
{
    this->_logicGates[outPins] = &logicGate;

    for (const auto& inPin : inPins) logicGate.setLink(inPin, *this, inPin);

    for (const auto& outPin : outPins) this->setLink(outPin, logicGate, outPin);
}

void nts::AChipset::removeLogicGate(const std::vector<size_t>& outPins)
{
    delete this->_logicGates[outPins];

    for (const auto& outPin : outPins) this->_links.erase(outPin);
}
