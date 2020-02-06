/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_INPUT_HPP
#define OOP_NANOTEKSPICE_2019_INPUT_HPP

#include "../nts/AComponent.hpp"

namespace special {

class Input : public nts::AComponent {
   public:
    Input() = default;
    nts::Tristate compute(std::size_t pin) override;
    void setState(nts::Tristate state);

   private:
    nts::Tristate _state = nts::UNDEFINED;
};

}  // namespace special

#endif  // OOP_NANOTEKSPICE_2019_INPUT_HPP
