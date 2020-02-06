/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AChipset.cpp
*/

#include "AChipset.hpp"

void nts::AChipset::addLogicGate(const std::vector<size_t>& inPins,
    const std::vector<size_t>& outPins, IComponent& logicGate)
{
    for (const auto& inPin : inPins) logicGate.setLink(inPin, *this, inPin);

    for (const auto& outPin : outPins) this->setLink(outPin, logicGate, outPin);
}

void nts::AChipset::removeLogicGate(std::vector<size_t> outPins)
{
    for (const auto& outPin : outPins) this->_links.erase(outPin);
}
