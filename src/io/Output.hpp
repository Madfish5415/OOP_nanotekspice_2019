/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_OUTPUT_HPP
#define OOP_NANOTEKSPICE_2019_OUTPUT_HPP

#include "nts/AComponent.hpp"

namespace io {

class Output : public nts::AComponent {
   public:
    Output();

   public:
    nts::Tristate compute(std::size_t pin) override;
};

}  // namespace io

#endif  // OOP_NANOTEKSPICE_2019_OUTPUT_HPP
