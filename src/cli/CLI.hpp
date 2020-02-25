/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CLI.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_CLI_HPP
#define OOP_NANOTEKSPICE_2019_CLI_HPP

#include <string>
#include <vector>

#include "nts/Circuit.hpp"
#include "parser/Parser.hpp"

#define DISPLAY_COMMAND ("display")
#define DUMP_COMMAND ("dump")
#define EXIT_COMMAND ("exit")
#define INPUT_COMMAND ("input")
#define LOOP_COMMAND ("loop")
#define SIMULATE_COMMAND ("simulate")

namespace cli {

class CLI {
   public:
    CLI(std::string path, std::vector<std::string> init);
    void run();

   private:
    parser::Parser _parser;
    const std::string _path;
    const std::vector<std::string> _init;
    nts::Circuit* _circuit;

   private:
    void init();
    void display();
    void dump();
    void input(const std::string& command);
    void loop();
    void simulate();
};

}  // namespace cli

#endif  // OOP_NANOTEKSPICE_2019_CLI_HPP
