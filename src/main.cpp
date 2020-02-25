/*
** EPITECH PROJECT, 2020
** bootstrap_nanotekspice
** File description:
** main.cpp
*/

#include <fstream>
#include <iostream>
#include <vector>

#include "cli/CLI.hpp"
#include "io/Input.hpp"
#include "io/Output.hpp"
#include "nts/Factory.hpp"
#include "util/def.hpp"

static void registerAll()
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

static void errors(int argc, char **argv)
{
    if (argc < 3) throw std::logic_error("Not enough arguments");

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
