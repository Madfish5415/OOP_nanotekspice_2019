/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NOR.cpp
*/

#include "NOR.hpp"

#include "gate/OR.hpp"
#include "gate/NOT.hpp"

component::NOR::NOR(const std::set<size_t>& INs, const std::set<size_t>& OUTs)
    : Container("NOR", INs, OUTs)
{
    IComponent::pointer and1 = IComponent::pointer(new gate::OR(INs, {0}));
    IComponent::pointer not1 = IComponent::pointer(new gate::NOT({0}, OUTs));

    for (const auto& in : INs) and1->setLink(in, *this, in);

    not1->setLink(0, *and1, 0);

    for (const auto& out : OUTs) this->setLink(out, *not1, out);

    this->addComponent("and1", and1);
    this->addComponent("not1", not1);
}
