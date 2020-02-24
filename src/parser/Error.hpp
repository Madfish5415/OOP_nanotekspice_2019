/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Error.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_PARSER_ERROR_HPP
#define OOP_NANOTEKSPICE_2019_PARSER_ERROR_HPP

#include <cstddef>
#include <string>

#include "nts/Error.hpp"

namespace parser {

class Error : public nts::Error {
   public:
    Error(
        const std::string& file, std::size_t line, const std::string& message);
};

}  // namespace parser

#endif  // OOP_NANOTEKSPICE_2019_PARSER_ERROR_HPP
