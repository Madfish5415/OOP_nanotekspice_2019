/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_CLOCK_HPP
#define OOP_NANOTEKSPICE_2019_CLOCK_HPP

#include "../nts/AComponent.hpp"

namespace special {

class Clock : public nts::AComponent {
   public:
    Clock() = default;
    nts::Tristate compute(std::size_t pin) override;
    void setState(nts::Tristate state);

   private:
    nts::Tristate _state = nts::UNDEFINED;
};

}  // namespace special

#endif  // OOP_NANOTEKSPICE_2019_CLOCK_HPP
