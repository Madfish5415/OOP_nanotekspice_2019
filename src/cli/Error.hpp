/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Error.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_CLI_ERROR_HPP
#define OOP_NANOTEKSPICE_2019_CLI_ERROR_HPP

#include <exception>
#include <string>

#define ERR_INPUT ("Invalid input")
#define ERR_INPUT_FORMAT ("Invalid input format")
#define ERR_INPUT_DOESNT_EXIST ("Clock/Input doesn't exist")
#define ERR_INPUT_VALUE ("Invalid input value")
#define ERR_INPUT_NOT_INITIALIZED ("Clock/Input not initialized")
#define ERR_UNKNOWN_COMMAND ("Unknown command")

namespace cli {

class Error : public std::exception {
   public:
    explicit Error(const std::string& error);
    const char * what() const noexcept override;

   private:
    std::string _message;
};

class ErrorRuntime : public std::exception {
   public:
    explicit ErrorRuntime(const std::string& command, const std::string& error);
    const char * what() const noexcept override;

   private:
    std::string _message;
};

}  // namespace cli

#endif  // OOP_NANOTEKSPICE_2019_CLI_ERROR_HPP
