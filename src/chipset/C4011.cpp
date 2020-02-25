/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4011.cpp
*/

#include "../gate/NOT.hpp"
#include "../gate/AND.hpp"
#include "C4011.hpp"

chipset::C4011::C4011() : nts::Container("4011", {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
{
    IComponent::pointer and1 = static_cast<std::unique_ptr<IComponent>>(new gate::AND({1, 2, 3}, {4}));
    IComponent::pointer and2 = static_cast<std::unique_ptr<IComponent>>(new gate::AND({1, 2, 3}, {4}));
    IComponent::pointer and3 = static_cast<std::unique_ptr<IComponent>>(new gate::AND({1, 2, 3}, {4}));
    IComponent::pointer and4 = static_cast<std::unique_ptr<IComponent>>(new gate::AND({1, 2, 3}, {4}));

    IComponent::pointer not1 = static_cast<std::unique_ptr<IComponent>>(new gate::NOT({1}, {2}));
    IComponent::pointer not2 = static_cast<std::unique_ptr<IComponent>>(new gate::NOT({1}, {2}));
    IComponent::pointer not3 = static_cast<std::unique_ptr<IComponent>>(new gate::NOT({1}, {2}));
    IComponent::pointer not4 = static_cast<std::unique_ptr<IComponent>>(new gate::NOT({1}, {2}));

    not1->setLink(1, *and1, 4);
    not2->setLink(1, *and2, 4);
    not3->setLink(1, *and3, 4);
    not4->setLink(1, *and4, 4);

    and1->setLink(1, *this, 1);
    and1->setLink(2, *this, 2);
    this->setLink(3, *not1, 2);

    and2->setLink(1, *this, 5);
    and2->setLink(2, *this, 6);
    this->setLink(4, *not2, 2);

    and3->setLink(1, *this, 8);
    and3->setLink(2, *this, 9);
    this->setLink(10, *not3, 2);

    and4->setLink(1, *this, 12);
    and4->setLink(2, *this, 13);
    this->setLink(11, *not4, 2);

    this->addComponent("not1", not1);
    this->addComponent("not2", not2);
    this->addComponent("not3", not3);
    this->addComponent("not4", not4);
    this->addComponent("and1", and1);
    this->addComponent("and2", and2);
    this->addComponent("and3", and3);
    this->addComponent("and4", and4);
}
