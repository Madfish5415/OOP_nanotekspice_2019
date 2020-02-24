/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parser.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_PARSER_HPP
#define OOP_NANOTEKSPICE_2019_PARSER_HPP

#include <nts/Error.hpp>

#include "nts/Circuit.hpp"

namespace parser {

class Parser {
   public:
    nts::Circuit& parse(const std::string& path);

   private:
    std::map<size_t, std::string> _lines;
    nts::Circuit _circuit;

   private:
    void fill(const std::string& path);
    void clean();
    void generate();
};

}

#endif  // OOP_NANOTEKSPICE_2019_PARSER_HPP
