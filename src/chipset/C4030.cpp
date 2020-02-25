/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4030.cpp
*/

#include "gate/XOR.hpp"
#include "C4030.hpp"

chipset::C4030::C4030()
    : nts::Container("4030", {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
{
    IComponent::pointer xor1 = IComponent::pointer(new gate::XOR({1, 2}, {3}));
    IComponent::pointer xor2 = IComponent::pointer(new gate::XOR({1, 2}, {3}));
    IComponent::pointer xor3 = IComponent::pointer(new gate::XOR({1, 2}, {3}));
    IComponent::pointer xor4 = IComponent::pointer(new gate::XOR({1, 2}, {3}));

    xor1->setLink(1, *this, 1);
    xor1->setLink(2, *this, 2);
    this->setLink(3, *xor1, 3);

    xor2->setLink(1, *this, 5);
    xor2->setLink(2, *this, 6);
    this->setLink(4, *xor2, 3);

    xor3->setLink(1, *this, 8);
    xor3->setLink(2, *this, 9);
    this->setLink(10, *xor3, 3);

    xor4->setLink(1, *this, 12);
    xor4->setLink(2, *this, 13);
    this->setLink(11, *xor4, 3);

    this->addComponent("xor1", xor1);
    this->addComponent("xor2", xor2);
    this->addComponent("xor3", xor3);
    this->addComponent("xor4", xor4);
}
