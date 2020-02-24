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

#define ERR_DUPLICATE_CHIPSETS_LABEL ("Duplicate chipsets label")
#define ERR_DUPLICATE_LINKS_LABEL ("Duplicate links label")
#define ERR_LINKS_BEFORE_CHIPSETS ("Links label before chipsets label")
#define ERR_NO_CHIPSETS_LABEL ("No chipsets label")
#define ERR_NO_LINKS_LABEL ("No links label")
#define ERR_COMPONENT_DECLARATION_FORMAT ("Invalid component declaration format")
#define ERR_COMPONENT_ALREADY_EXISTS ("Component already exists")
#define ERR_COMPONENT_LINK_FORMAT ("Invalid component link format")
#define ERR_COMPONENT_DOESNT_EXISTS ("Component doesn't exists")
#define ERR_PIN_NOT_A_NUMBER ("Pin is not a number")
#define ERR_PIN_NOT_AN_IN ("Pin is not an IN pin")
#define ERR_PIN_NOT_AN_OUT ("Pin is not an OUT pin")

#include "nts/Circuit.hpp"

namespace parser {

class Parser {
   public:
    nts::Circuit& parse(const std::string& path);

   private:
    std::string _file;
    std::map<size_t, std::string> _lines;
    nts::Circuit _circuit;

   private:
    void fill(const std::string& path);
    void clean();
    void generate();
    void checkLabels();
    void addComponents();
    void linkComponents();
};

}  // namespace parser

#endif  // OOP_NANOTEKSPICE_2019_PARSER_HPP
