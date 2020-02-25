/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4071.cpp
*/

#include "gate/OR.hpp"
#include "C4071.hpp"

chipset::C4071::C4071()
    : nts::Container("4071", {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
{
    std::unique_ptr<nts::IComponent> or1 = std::unique_ptr<nts::IComponent>(new gate::OR({1, 2}, {3}));
    std::unique_ptr<nts::IComponent> or2 = std::unique_ptr<nts::IComponent>(new gate::OR({1, 2}, {3}));
    std::unique_ptr<nts::IComponent> or3 = std::unique_ptr<nts::IComponent>(new gate::OR({1, 2}, {3}));
    std::unique_ptr<nts::IComponent> or4 = std::unique_ptr<nts::IComponent>(new gate::OR({1, 2}, {3}));

    or1->setLink(1, *this, 1);
    or1->setLink(2, *this, 2);
    this->setLink(3, *or1, 3);

    or2->setLink(1, *this, 5);
    or2->setLink(2, *this, 6);
    this->setLink(4, *or2, 3);

    or3->setLink(1, *this, 8);
    or3->setLink(2, *this, 9);
    this->setLink(10, *or3, 3);

    or4->setLink(1, *this, 12);
    or4->setLink(2, *this, 13);
    this->setLink(11, *or4, 3);

    this->addComponent("or1", or1);
    this->addComponent("or2", or2);
    this->addComponent("or3", or3);
    this->addComponent("or4", or4);
}
