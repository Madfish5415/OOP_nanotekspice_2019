/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_CLOCK_HPP
#define OOP_NANOTEKSPICE_2019_CLOCK_HPP

#include "../nts/SpecialComponent.hpp"

namespace special {

class Clock : public nts::SpecialComponent {
   public:
    explicit Clock(nts::Tristate state);
    nts::Tristate compute(std::size_t pin) override;
};

}  // namespace special

#endif  // OOP_NANOTEKSPICE_2019_CLOCK_HPP
