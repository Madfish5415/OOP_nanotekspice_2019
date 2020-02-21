/*
** EPITECH PROJECT, 2020
** bootstrap_nanotekspice
** File description:
** main.cpp
*/

#include <gate/AND.hpp>
#include <io/Clock.hpp>
#include <io/Input.hpp>
#include <io/Output.hpp>
#include <nts/Circuit.hpp>
#include <nts/Factory.hpp>

void registerAll()
{
    nts::Factory::Register(
        "Clock", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new io::Clock());
        });
    nts::Factory::Register(
        "False", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new io::Input());
        });
    nts::Factory::Register(
        "Input", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new io::Input());
        });
    nts::Factory::Register(
        "Output", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new io::Output());
        });
    nts::Factory::Register(
        "True", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new io::Output());
        });
    nts::Factory::Register(
        "True", [](auto) -> std::unique_ptr<nts::IComponent> {
          return std::unique_ptr<nts::IComponent>(new io::Output());
        });
}

int main()
{
    registerAll();

    std::unique_ptr<nts::IComponent> input1 = nts::Factory::Create("Input");
    std::unique_ptr<nts::IComponent> clock1 = nts::Factory::Create("Clock");
    std::unique_ptr<nts::IComponent> output1 = nts::Factory::Create("Output");
    std::unique_ptr<nts::IComponent> and1 =
        std::unique_ptr<nts::IComponent>(new gate::AND({1, 2}, {3}));
    std::unique_ptr<nts::IComponent> and2 =
        std::unique_ptr<nts::IComponent>(new gate::AND({1, 2}, {3}));
    nts::Circuit circuit = nts::Circuit();

    clock1->setValue("1");
    input1->setValue("1");

    and1->setLink(1, *input1, 1);
    and1->setLink(2, *and2, 3);

    and2->setLink(1, *clock1, 1);
    and2->setLink(2, *and1, 3);

    output1->setLink(1, *and2, 3);

    circuit.addComponent("clock1", clock1);
    circuit.addComponent("input1", input1);
    circuit.addComponent("and1", and1);
    circuit.addComponent("and2", and2);
    circuit.addComponent("output1", output1);

    circuit.simulate();
    circuit.display();
    circuit.reset();
    circuit.simulate();
    circuit.display();
    circuit.reset();
    circuit.simulate();
    circuit.display();
    circuit.reset();
}