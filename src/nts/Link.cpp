/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Link.cpp
*/

#include "Link.hpp"

nts::Link::Link(nts::IComponent *other, size_t otherPin)
    : _other(other), _otherPin(otherPin)
{
}

nts::IComponent *nts::Link::getOther() const
{
    return this->_other;
}

size_t nts::Link::getOtherPin() const
{
    return this->_otherPin;
}
