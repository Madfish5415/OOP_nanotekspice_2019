/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Undefined.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_UNDEFINED_HPP
#define OOP_NANOTEKSPICE_2019_UNDEFINED_HPP

#include "nts/AComponent.hpp"

namespace io {

namespace mock {

class Undefined : public nts::AComponent {
   public:
    Undefined();

   public:
    nts::Tristate compute(std::size_t pin) override;
};

}

}

#endif  // OOP_NANOTEKSPICE_2019_UNDEFINED_HPP
