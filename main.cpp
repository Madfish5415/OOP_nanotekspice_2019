/*
** EPITECH PROJECT, 2020
** bootstrap_nanotekspice
** File description:
** main.cpp
*/

#include "src/chipset/C4071.hpp"
#include "src/nts/Circuit.hpp"
#include "src/special/Input.hpp"
#include "src/special/Output.hpp"

int main()
{
    nts::Circuit circuit;
    special::Input i1;
    special::Input i2;
    special::Output o1;
    chipset::C4071 c4071;

    i1.setState(nts::FALSE);
    i2.setState(nts::UNDEFINED);

    circuit.addComponent("i1", i1);
    circuit.addComponent("i2", i2);
    circuit.addComponent("o1", o1);
    circuit.addComponent("c4071", c4071);

    circuit.getComponent("c4071").setLink(1, circuit.getComponent("i1"), 1);
    circuit.getComponent("c4071").setLink(2, circuit.getComponent("i2"), 1);
    circuit.getComponent("o1").setLink(1, circuit.getComponent("c4071"), 3);

    circuit.simulate();
    circuit.display();
}