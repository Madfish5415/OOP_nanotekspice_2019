/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_INPUT_HPP
#define OOP_NANOTEKSPICE_2019_INPUT_HPP

#include "nts/AComponent.hpp"

namespace io {

class Input : public nts::AComponent {
   public:
    Input();

   public:
    nts::Tristate compute(std::size_t pin) override;
};

}  // namespace io

#endif  // OOP_NANOTEKSPICE_2019_INPUT_HPP
