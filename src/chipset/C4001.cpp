/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4001.cpp
*/

#include "../gate/NOT.hpp"
#include "../gate/OR.hpp"
#include "C4001.hpp"

chipset::C4001::C4001() : nts::Container("4011", {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
{
    IComponent::pointer or1 = IComponent::pointer(new gate::OR({1, 2, 3}, {4}));
    IComponent::pointer or2 = IComponent::pointer(new gate::OR({1, 2, 3}, {4}));
    IComponent::pointer or3 = IComponent::pointer(new gate::OR({1, 2, 3}, {4}));
    IComponent::pointer or4 = IComponent::pointer(new gate::OR({1, 2, 3}, {4}));

    IComponent::pointer not1 = IComponent::pointer(new gate::NOT({1}, {2}));
    IComponent::pointer not2 = IComponent::pointer(new gate::NOT({1}, {2}));
    IComponent::pointer not3 = IComponent::pointer(new gate::NOT({1}, {2}));
    IComponent::pointer not4 = IComponent::pointer(new gate::NOT({1}, {2}));

    not1->setLink(1, *or1, 4);
    not2->setLink(1, *or2, 4);
    not3->setLink(1, *or3, 4);
    not4->setLink(1, *or4, 4);

    or1->setLink(1, *this, 1);
    or1->setLink(2, *this, 2);
    this->setLink(3, *not1, 2);

    or2->setLink(1, *this, 5);
    or2->setLink(2, *this, 6);
    this->setLink(4, *not2, 2);

    or3->setLink(1, *this, 8);
    or3->setLink(2, *this, 9);
    this->setLink(10, *not3, 2);

    or4->setLink(1, *this, 12);
    or4->setLink(2, *this, 13);
    this->setLink(11, *not4, 2);

    this->addComponent("not1", not1);
    this->addComponent("not2", not2);
    this->addComponent("not3", not3);
    this->addComponent("not4", not4);
    this->addComponent("or1", or1);
    this->addComponent("or2", or2);
    this->addComponent("or3", or3);
    this->addComponent("or4", or4);
}
