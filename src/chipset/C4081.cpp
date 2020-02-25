/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4081.cpp
*/

#include "gate/AND.hpp"
#include "C4081.hpp"

chipset::C4081::C4081()
    : nts::Container("4081", {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
{
    std::unique_ptr<nts::IComponent> and1 = std::unique_ptr<nts::IComponent>(new gate::AND({1, 2}, {3}));
    std::unique_ptr<nts::IComponent> and2 = std::unique_ptr<nts::IComponent>(new gate::AND({1, 2}, {3}));
    std::unique_ptr<nts::IComponent> and3 = std::unique_ptr<nts::IComponent>(new gate::AND({1, 2}, {3}));
    std::unique_ptr<nts::IComponent> and4 = std::unique_ptr<nts::IComponent>(new gate::AND({1, 2}, {3}));

    and1->setLink(1, *this, 1);
    and1->setLink(2, *this, 2);
    this->setLink(3, *and1, 3);

    and2->setLink(1, *this, 5);
    and2->setLink(2, *this, 6);
    this->setLink(4, *and2, 3);

    and3->setLink(1, *this, 8);
    and3->setLink(2, *this, 9);
    this->setLink(10, *and3, 3);

    and4->setLink(1, *this, 12);
    and4->setLink(2, *this, 13);
    this->setLink(11, *and4, 3);

    this->addComponent("and1", and1);
    this->addComponent("and2", and2);
    this->addComponent("and3", and3);
    this->addComponent("and4", and4);
}
