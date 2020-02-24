/*
** EPITECH PROJECT, 2020
** bootstrap_nanotekspice
** File description:
** main.cpp
*/

#include <io/Input.hpp>
#include <io/Output.hpp>
#include <nts/Factory.hpp>
#include <parser/Parser.hpp>

void registerAll()
{
    nts::Factory::Register(
        "input", [](auto) -> std::unique_ptr<nts::IComponent> {
          return std::unique_ptr<nts::IComponent>(new io::Input());
        });
    nts::Factory::Register(
        "output", [](auto) -> std::unique_ptr<nts::IComponent> {
          return std::unique_ptr<nts::IComponent>(new io::Output());
        });
}

int main()
{
    registerAll();

    parser::Parser p;

    auto &circuit = p.parse("stupid.nts");

    circuit.simulate();
    circuit.display();
    circuit.dump();
}
