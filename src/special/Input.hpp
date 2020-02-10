/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_INPUT_HPP
#define OOP_NANOTEKSPICE_2019_INPUT_HPP

#include "../nts/SpecialComponent.hpp"

namespace special {

class Input : public nts::SpecialComponent {
   public:
    explicit Input(nts::Tristate state);
};

}  // namespace special

#endif  // OOP_NANOTEKSPICE_2019_INPUT_HPP
