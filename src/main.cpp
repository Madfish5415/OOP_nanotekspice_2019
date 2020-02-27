/*
** EPITECH PROJECT, 2020
** bootstrap_nanotekspice
** File description:
** main.cpp
*/

#include <fstream>
#include <iostream>
#include <vector>

#include "chipset/C4001.hpp"
#include "chipset/C4011.hpp"
#include "chipset/C4013.hpp"
#include "chipset/C4030.hpp"
#include "chipset/C4069.hpp"
#include "chipset/C4071.hpp"
#include "chipset/C4081.hpp"
#include "cli/CLI.hpp"
#include "io/Clock.hpp"
#include "io/False.hpp"
#include "io/Input.hpp"
#include "io/Output.hpp"
#include "io/True.hpp"
#include "nts/Factory.hpp"
#include "util/def.hpp"

static void registerAll()
{
    nts::Factory::Register(
        "4001", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new chipset::C4001());
        });
    nts::Factory::Register(
        "4011", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new chipset::C4011());
        });
    nts::Factory::Register(
        "4013", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new chipset::C4013());
        });
    nts::Factory::Register(
        "4030", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new chipset::C4030());
        });
    nts::Factory::Register(
        "4069", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new chipset::C4069());
        });
    nts::Factory::Register(
        "4071", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new chipset::C4071());
        });
    nts::Factory::Register(
        "4081", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new chipset::C4081());
        });
    nts::Factory::Register(
        "clock", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new io::Clock());
        });
    nts::Factory::Register(
        "false", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new io::False());
        });
    nts::Factory::Register(
        "input", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new io::Input());
        });
    nts::Factory::Register(
        "output", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new io::Output());
        });
    nts::Factory::Register(
        "true", [](auto) -> std::unique_ptr<nts::IComponent> {
            return std::unique_ptr<nts::IComponent>(new io::True());
        });
}

static void errors(int argc, char **argv)
{
    if (argc < 2) throw std::logic_error("Not enough arguments");

    std::ifstream file{argv[1]};

    if (file.fail()) throw std::logic_error("File doesn't exist");
}

int main(int argc, char **argv)
{
    registerAll();

    try {
        errors(argc, argv);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;

        return FAILURE;
    }

    std::string path = argv[1];
    std::vector<std::string> init;

    for (int i = 2; i < argc; i++) init.emplace_back(argv[i]);

    cli::CLI *c;

    try {
        c = new cli::CLI(path, init);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;

        return FAILURE;
    }

    try {
        c->run();
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;

        return FAILURE;
    }

    delete c;

    return SUCCESS;
}
