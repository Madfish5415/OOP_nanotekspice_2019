/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_FALSE_HPP
#define OOP_NANOTEKSPICE_2019_FALSE_HPP

#include "nts/AComponent.hpp"

namespace io {

class False : public nts::AComponent {
   public:
    False();

   public:
    nts::Tristate compute(std::size_t pin) override;
};

}  // namespace io

#endif  // OOP_NANOTEKSPICE_2019_FALSE_HPP
