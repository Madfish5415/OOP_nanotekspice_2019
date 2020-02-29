/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4013.cpp
*/

#include "../component/DFlipFlop.hpp"
#include "C4013.hpp"

chipset::C4013::C4013() : nts::Container("4013", {3, 4, 5, 6, 8, 9, 10, 11}, {1, 2, 12, 13})
{
    IComponent::pointer DFlipFlop1 = IComponent::pointer(new container::DFlipFlop());
    IComponent::pointer DFlipFlop2 = IComponent::pointer(new container::DFlipFlop());

    DFlipFlop1->setLink(1, *this, 6);
    DFlipFlop1->setLink(2, *this, 4);
    DFlipFlop1->setLink(3, *this, 3);
    DFlipFlop1->setLink(4, *this, 5);
    this->setLink(1, *DFlipFlop1, 5);
    this->setLink(2, *DFlipFlop1, 6);

    DFlipFlop2->setLink(1, *this, 8);
    DFlipFlop2->setLink(2, *this, 10);
    DFlipFlop2->setLink(3, *this, 11);
    DFlipFlop2->setLink(4, *this, 9);
    this->setLink(13, *DFlipFlop2, 5);
    this->setLink(12, *DFlipFlop2, 6);

    this->addComponent("DFlipFlop1", DFlipFlop1);
    this->addComponent("DFlipFlop2", DFlipFlop2);
}
