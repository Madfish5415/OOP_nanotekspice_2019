/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NAND.cpp
*/

#include "NAND.hpp"

#include "gate/AND.hpp"
#include "gate/NOT.hpp"

container::NAND::NAND(const std::set<size_t>& INs, const std::set<size_t>& OUTs)
    : Container("NAND", INs, OUTs)
{
    IComponent::pointer and1 = IComponent::pointer(new gate::AND(INs, {0}));
    IComponent::pointer not1 = IComponent::pointer(new gate::NOT({0}, OUTs));

    for (const auto& in : INs) and1->setLink(in, *this, in);

    not1->setLink(0, *and1, 0);

    for (const auto& out : OUTs) this->setLink(out, *not1, out);

    this->addComponent("and1", and1);
    this->addComponent("not1", not1);
}
