/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Error.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_ERROR_HPP
#define OOP_NANOTEKSPICE_2019_ERROR_HPP

#include <string>

namespace nts {

class Error : public std::exception {
   public:
    explicit Error(const std::string& component, const std::string& error = "");
    const char* what() const noexcept override;

   protected:
    std::string _message;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_ERROR_HPP