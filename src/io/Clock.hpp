/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_CLOCK_HPP
#define OOP_NANOTEKSPICE_2019_CLOCK_HPP

#include "nts/AComponent.hpp"

namespace io {

class Clock : public nts::AComponent {
   public:
    Clock();

   public:
    nts::Tristate compute(std::size_t pin) override;
};

}

#endif  // OOP_NANOTEKSPICE_2019_CLOCK_HPP
