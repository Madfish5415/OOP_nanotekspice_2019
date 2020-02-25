/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** DFlipFlop.cpp
*/

#include "../gate/NOT.hpp"
#include "../gate/AND.hpp"
#include "DFlipFlop.hpp"

component::DFlipFlop::DFlipFlop() : nts::Container("DFlipFlop", {1, 2, 3, 4}, {5, 6})
{
    std::unique_ptr<IComponent> not1 = std::unique_ptr<IComponent>(new gate::NOT({1}, {2}));
    std::unique_ptr<IComponent> not2 = std::unique_ptr<IComponent>(new gate::NOT({1}, {2}));
    std::unique_ptr<IComponent> not3 = std::unique_ptr<IComponent>(new gate::NOT({1}, {2}));
    std::unique_ptr<IComponent> not4 = std::unique_ptr<IComponent>(new gate::NOT({1}, {2}));
    std::unique_ptr<IComponent> not5 = std::unique_ptr<IComponent>(new gate::NOT({1}, {2}));
    std::unique_ptr<IComponent> not6 = std::unique_ptr<IComponent>(new gate::NOT({1}, {2}));
    std::unique_ptr<IComponent> not7 = std::unique_ptr<IComponent>(new gate::NOT({1}, {2}));
    std::unique_ptr<IComponent> not8 = std::unique_ptr<IComponent>(new gate::NOT({1}, {2}));

    std::unique_ptr<IComponent> and1 = std::unique_ptr<IComponent>(new gate::AND({1, 2, 3}, {4}));
    std::unique_ptr<IComponent> and2 = std::unique_ptr<IComponent>(new gate::AND({1, 2, 3}, {4}));
    std::unique_ptr<IComponent> and3 = std::unique_ptr<IComponent>(new gate::AND({1, 2, 3}, {4}));
    std::unique_ptr<IComponent> and4 = std::unique_ptr<IComponent>(new gate::AND({1, 2, 3}, {4}));
    std::unique_ptr<IComponent> and5 = std::unique_ptr<IComponent>(new gate::AND({1, 2, 3}, {4}));
    std::unique_ptr<IComponent> and6 = std::unique_ptr<IComponent>(new gate::AND({1, 2, 3}, {4}));

    not1->setLink(1, *and1, 4);
    not2->setLink(1, *and2, 4);
    not3->setLink(1, *and3, 4);
    not4->setLink(1, *and4, 4);
    not5->setLink(1, *and5, 4);
    not6->setLink(1, *and6, 4);
    not7->setLink(1, *this, 1);
    not8->setLink(1, *this, 2);

    and1->setLink(1, *not2, 2);
    and1->setLink(2, *not8, 2);
    and1->setLink(3, *this, 4);

    and2->setLink(1, *not3, 2);
    and2->setLink(2, *this, 3);
    and2->setLink(3, *not1, 2);

    and3->setLink(1, *not4, 2);
    and3->setLink(2, *not8, 2);
    and3->setLink(3, *this, 3);

    and4->setLink(1, *not7, 2);
    and4->setLink(2, *not1, 2);
    and4->setLink(3, *not3, 2);

    and5->setLink(1, *not6, 2);
    and5->setLink(2, *not8, 2);
    and5->setLink(3, *not2, 2);

    and6->setLink(1, *not7, 2);
    and6->setLink(2, *not3, 2);
    and6->setLink(3, *not5, 2);

    this->setLink(5, *not6, 2);
    this->setLink(6, *not5, 2);

    this->addComponent("not1", not1);
    this->addComponent("not2", not2);
    this->addComponent("not3", not3);
    this->addComponent("not4", not4);
    this->addComponent("not5", not5);
    this->addComponent("not6", not6);
    this->addComponent("not7", not7);
    this->addComponent("not8", not8);
    this->addComponent("and1", and1);
    this->addComponent("and2", and2);
    this->addComponent("and3", and3);
    this->addComponent("and4", and4);
    this->addComponent("and5", and5);
    this->addComponent("and6", and6);
}
