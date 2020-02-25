/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CLI.cpp
*/

#include "CLI.hpp"

#include <csignal>
#include <iostream>
#include <limits>
#include <nts/Error.hpp>
#include <util/string.hpp>
#include <utility>

#include "Error.hpp"
#include "parser/Parser.hpp"

std::sig_atomic_t sig;

static void cleanCin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static std::string getCin()
{
    std::string command;

    std::cout << "> ";

    while (!(std::cin >> command)) {
        if (std::cin.eof()) break;

        std::cout << ERR_INPUT << std::endl;
        cleanCin();
    }

    return command;
}

cli::CLI::CLI(std::string path, std::vector<std::string> init)
    : _parser(parser::Parser(path)),
      _path(std::move(path)),
      _init(std::move(init))
{
    this->_circuit = &this->_parser.parse();
    this->init();
}

void cli::CLI::run()
{
    this->simulate();
    this->display();

    std::signal(SIGINT, [](int signal) -> void { sig = signal; });

    while (true) {
        std::string command = getCin();

        if (command == EXIT_COMMAND || std::cin.eof()) break;

        try {
            if (command == DISPLAY_COMMAND)
                this->display();
            else if (command == DUMP_COMMAND)
                this->dump();
            else if (command == LOOP_COMMAND)
                this->loop();
            else if (command == SIMULATE_COMMAND)
                this->simulate();
            else if (command.find('=') != std::string::npos)
                this->input(command);
            else
                throw ErrorRuntime(command, ERR_UNKNOWN_COMMAND);
        } catch (ErrorRuntime& e) {
            std::cout << e.what() << std::endl;
        }

        cleanCin();
    }
}

void cli::CLI::init()
{
    const auto& components = this->_circuit->getComponents();

    for (const auto& item : this->_init) {
        std::vector<std::string> tokens = util::string::split(item, '=');

        if (tokens.size() != 2) throw Error(ERR_INPUT_FORMAT);

        if ((components.count(tokens[0]) == 0) ||
            ((components.at(tokens[0])->getType() != "Input") &&
                (components.at(tokens[0])->getType() != "Clock")))
            throw Error(ERR_INPUT_DOESNT_EXIST);

        if ((tokens[1] != "0") && (tokens[1] != "1"))
            throw Error(ERR_INPUT_VALUE);

        components.at(tokens[0])->setValue(tokens[1]);
    }

    for (const auto& component : components) {
        if ((component.second->getType() != "Input") &&
            (component.second->getType() != "Clock"))
            continue;
        if (component.second->getValue().empty())
            throw Error(ERR_INPUT_NOT_INITIALIZED);
    }
}

void cli::CLI::display()
{
    this->_circuit->display();
}

void cli::CLI::dump()
{
    this->_circuit->dump();
}

void cli::CLI::input(const std::string& command)
{
    const auto& components = this->_circuit->getComponents();

    std::vector<std::string> tokens = util::string::split(command, '=');

    if (tokens.size() != 2) throw ErrorRuntime(INPUT_COMMAND, ERR_INPUT_FORMAT);

    if ((components.count(tokens[0]) == 0) ||
        ((components.at(tokens[0])->getType() != "Input") &&
            (components.at(tokens[0])->getType() != "Clock")))
        throw ErrorRuntime(INPUT_COMMAND, ERR_INPUT_DOESNT_EXIST);

    if ((tokens[1] != "0") && (tokens[1] != "1"))
        throw Error(ERR_INPUT_VALUE);

    components.at(tokens[0])->setValue(tokens[1]);
}

void cli::CLI::loop()
{
    while (sig != SIGINT) {
        this->simulate();
        this->display();
    }

    sig = 0;
}

void cli::CLI::simulate()
{
    try {
        this->_circuit->simulate();
    } catch (nts::Error& e) {
        throw ErrorRuntime(SIMULATE_COMMAND, e.what());
    }

    this->_circuit->reset();
}
