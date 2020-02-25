/*
** EPITECH PROJECT, 2020
** bootstrap_nanotekspice
** File description:
** main.cpp
*/

#include <algorithm>
#include <csignal>
#include <fstream>
#include <iostream>
#include <vector>

#include "io/Input.hpp"
#include "io/Output.hpp"
#include "nts/Error.hpp"
#include "nts/Factory.hpp"
#include "parser/Parser.hpp"
#include "util/def.hpp"
#include "util/string.hpp"

std::sig_atomic_t sigAtomic;

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

static void errors_pre(int argc, char **argv)
{
    if (argc < 3)
        throw nts::Error("Main", "Invalid format: file.nts input=value [...]");

    for (int i = 2; i < argc; i++) {
        std::vector<std::string> tokens = util::string::split(argv[i], '=');

        if (tokens.size() != 2)
            throw nts::Error(
                "Main", "Invalid format: file.nts input=value [...]");
    }

    std::ifstream file{argv[1]};

    if (file.fail()) throw nts::Error("Main", "File doesn't exists");
}

static void errors_post(int argc, char **argv, nts::Circuit *circuit)
{
    const auto &components = circuit->getComponents();
    std::vector<std::string> inputs;

    for (const auto &component : components)
        if (component.second->getType() == "Input")
            inputs.push_back(component.first);

    if ((unsigned long)(argc) < 2 + inputs.size())
        throw nts::Error("Main", "Missing initialization value of inputs");

    for (int i = 2; i < argc; i++) {
        std::vector<std::string> tokens = util::string::split(argv[i], '=');

        if (std::count(inputs.begin(), inputs.end(), tokens[0]) == 0)
            throw nts::Error("Main", "Input doesn't exists");
    }
}

static void cli(nts::Circuit *circuit)
{
    circuit->simulate();
    circuit->reset();
    circuit->display();

    std::string command;
    bool exit = false;

    std::signal(SIGINT, [](int signal) -> void { sigAtomic = signal; });

    while (!exit) {
        std::cout << "> ";
        std::cin >> command;

        if (std::cin.eof() || (command == "exit"))
            exit = true;
        else if (std::cin.fail())
            std::cout << "Input failed. Please retry" << std::endl;
        else if (command == "display")
            circuit->display();
        else if (command == "dump")
            circuit->dump();
        else if (command == "loop") {
            while (sigAtomic != SIGINT) {
                circuit->simulate();
                circuit->reset();
                circuit->display();
            }

            sigAtomic = 0;
        } else if (command == "simulate") {
            circuit->simulate();
            circuit->reset();
        } else {
            std::cout << "Unknown command. Available commands: display, dump, "
                         "exit, loop, simulate."
                      << std::endl;
        }

        command.clear();
    }
}

int main(int argc, char **argv)
{
    registerAll();

    try {
        errors_pre(argc, argv);
    } catch (nts::Error &e) {
        std::cout << "Error: " << e.what() << std::endl;

        return FAILURE;
    }

    parser::Parser p;
    nts::Circuit *circuit;

    try {
        circuit = &p.parse(argv[1]);
    } catch (nts::Error &e) {
        std::cout << "Error: " << e.what() << std::endl;

        return FAILURE;
    }

    try {
        errors_post(argc, argv, circuit);
    } catch (nts::Error &e) {
        std::cout << "Error: " << e.what() << std::endl;

        return FAILURE;
    }

    for (int i = 2; i < argc; i++) {
        std::vector<std::string> tokens = util::string::split(argv[i], '=');

        circuit->getComponents().at(tokens[0])->setValue(tokens[1]);
    }

    try {
        cli(circuit);
    } catch (nts::Error &e) {
        std::cout << "Error: " << e.what() << std::endl;

        return FAILURE;
    }

    return SUCCESS;
}
