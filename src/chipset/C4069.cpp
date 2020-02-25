/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4069.cpp
*/

#include "../gate/NOT.hpp"
#include "C4069.hpp"

chipset::C4069::C4069() : nts::Container("4069", {1, 3, 5, 9, 11, 13}, {2, 4, 6, 8, 10, 12})
{
    IComponent::pointer not1 = IComponent::pointer(new gate::NOT({1}, {2}));
    IComponent::pointer not2 = IComponent::pointer(new gate::NOT({1}, {2}));
    IComponent::pointer not3 = IComponent::pointer(new gate::NOT({1}, {2}));
    IComponent::pointer not4 = IComponent::pointer(new gate::NOT({1}, {2}));
    IComponent::pointer not5 = IComponent::pointer(new gate::NOT({1}, {2}));
    IComponent::pointer not6 = IComponent::pointer(new gate::NOT({1}, {2}));

    not1->setLink(1, *this, 1);
    this->setLink(2, *not1, 2);

    not2->setLink(1, *this, 3);
    this->setLink(4, *not2, 2);

    not3->setLink(1, *this, 5);
    this->setLink(6, *not3, 2);

    not4->setLink(1, *this, 9);
    this->setLink(8, *not4, 2);

    not5->setLink(1, *this, 11);
    this->setLink(10, *not5, 2);

    not6->setLink(1, *this, 13);
    this->setLink(12, *not6, 2);

    this->addComponent("not1", not1);
    this->addComponent("not2", not2);
    this->addComponent("not3", not3);
    this->addComponent("not4", not4);
    this->addComponent("not5", not5);
    this->addComponent("not6", not6);
}
