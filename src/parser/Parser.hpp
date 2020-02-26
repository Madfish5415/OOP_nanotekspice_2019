/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parser.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_PARSER_HPP
#define OOP_NANOTEKSPICE_2019_PARSER_HPP

#define CHIPSETS_LABEL (".chipsets:")
#define LINKS_LABEL (".links:")

#include "nts/Circuit.hpp"

namespace parser {

class Parser {
   public:
    explicit Parser(std::string path);
    nts::Circuit& parse();

   private:
    const std::string _path;
    std::map<std::size_t, std::string> _lines;
    nts::Circuit _circuit;

   private:
    void fill();
    void clean();
    void checkLabels();
    void addComponents();
    void linkComponents();
};

}  // namespace parser

#endif  // OOP_NANOTEKSPICE_2019_PARSER_HPP
