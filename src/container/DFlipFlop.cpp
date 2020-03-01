/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** DFlipFlop.cpp
*/

#include "DFlipFlop.hpp"

#include "gate/AND.hpp"
#include "gate/NOT.hpp"
#include "gate/OR.hpp"
#include "NOR.hpp"

/*
 * 1: clock
 * 2: reset
 * 3: data
 * 4: set
 * 5: Q
 * 6: -Q
 */

container::DFlipFlop::DFlipFlop() : nts::Container("DFlipFlop", {1, 2, 3, 4}, {5, 6})
{
    IComponent::pointer not1 = IComponent::pointer(new gate::NOT({1}, {2}));
    IComponent::pointer not2 = IComponent::pointer(new gate::NOT({1}, {2}));
    IComponent::pointer not3 = IComponent::pointer(new gate::NOT({1}, {2}));

    IComponent::pointer and1 = IComponent::pointer(new gate::AND({1, 2}, {3}));
    IComponent::pointer and2 = IComponent::pointer(new gate::AND({1, 2}, {3}));
    IComponent::pointer and3 = IComponent::pointer(new gate::AND({1, 2}, {3}));
    IComponent::pointer and4 = IComponent::pointer(new gate::AND({1, 2}, {3}));

    IComponent::pointer or1 = IComponent::pointer(new gate::OR({1, 2}, {3}));
    IComponent::pointer or2 = IComponent::pointer(new gate::OR({1, 2}, {3}));

    IComponent::pointer nor1 = IComponent::pointer(new NOR({1, 2}, {3}));
    IComponent::pointer nor2 = IComponent::pointer(new NOR({1, 2}, {3}));
    IComponent::pointer nor3 = IComponent::pointer(new NOR({1, 2}, {3}));
    IComponent::pointer nor4 = IComponent::pointer(new NOR({1, 2}, {3}));

    not3->setLink(1, *this, 1);

    and1->setLink(1, *this, 3);
    and1->setLink(2, *this, 1);

    or1->setLink(1, *and1, 3);
    or1->setLink(2, *and2, 3);

    nor1->setLink(1, *this, 4);
    nor1->setLink(2, *or1, 3);

    nor2->setLink(1, *nor1, 3);
    nor2->setLink(2, *this, 2);

    and2->setLink(1, *nor2, 3);
    and2->setLink(2, *not3, 2);

    and3->setLink(1, *nor1, 3);
    and3->setLink(2, *not3, 2);

    nor3->setLink(1, *and3, 3);
    nor3->setLink(2, *this, 2);

    nor4->setLink(1, *this, 4);
    nor4->setLink(2, *nor3, 3);

    and4->setLink(1, *nor4, 3);
    and4->setLink(2, *this, 1);

    or2->setLink(1, *and3, 3);
    or2->setLink(2, *and4, 3);

    not1->setLink(1, *or2, 3);
    not2->setLink(1, *nor3, 3);

    this->setLink(5, *not1, 2);
    this->setLink(6, *not2, 2);

    this->addComponent("not1", not1);
    this->addComponent("not2", not2);
    this->addComponent("not3", not3);
    this->addComponent("and1", and1);
    this->addComponent("and2", and2);
    this->addComponent("and3", and3);
    this->addComponent("and4", and4);
    this->addComponent("or1", or1);
    this->addComponent("or2", or2);
    this->addComponent("nor1", nor1);
    this->addComponent("nor2", nor2);
    this->addComponent("nor3", nor3);
    this->addComponent("nor4", nor4);
}
