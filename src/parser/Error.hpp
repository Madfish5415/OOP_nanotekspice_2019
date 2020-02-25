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

#define ERR_FILE_FAILED ("File open failed")
#define ERR_DUPLICATE_CHIPSETS_LABEL ("Duplicate chipsets label")
#define ERR_DUPLICATE_LINKS_LABEL ("Duplicate links label")
#define ERR_LINKS_BEFORE_CHIPSETS ("Links label before chipsets label")
#define ERR_NO_CHIPSETS_LABEL ("No chipsets label")
#define ERR_NO_LINKS_LABEL ("No links label")
#define ERR_COMPONENT_DECLARATION_FORMAT ("Invalid component declaration format")
#define ERR_COMPONENT_ALREADY_EXISTS ("Component already exists")
#define ERR_COMPONENT_LINK_FORMAT ("Invalid component link format")
#define ERR_COMPONENT_DOESNT_EXIST ("Component doesn't exist")
#define ERR_PIN_NOT_A_NUMBER ("Pin is not a number")
#define ERR_PIN_DOESNT_EXIST ("Pin doesn't exist")
#define ERR_PIN_CANT_LINK_IN ("IN pin can't be linked to another IN pin")
#define ERR_PIN_CANT_LINK_OUT ("OUT pin can't be linked to another OUT pin")

namespace parser {

class Error : public std::exception {
   public:
    explicit Error(const std::string& error);
    const char * what() const noexcept override;

   private:
    std::string _message;
};

class ErrorAtLine : public std::exception {
   public:
    ErrorAtLine(const std::string& path, std::size_t line, const std::string& error);
    const char * what() const noexcept override;

   private:
    std::string _message;
};

}  // namespace parser

#endif  // OOP_NANOTEKSPICE_2019_PARSER_ERROR_HPP
