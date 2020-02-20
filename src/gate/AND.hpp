/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AND.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_AND_HPP
#define OOP_NANOTEKSPICE_2019_AND_HPP

#include "nts/AComponent.hpp"

namespace gate {

class AND : public nts::AComponent {
   public:
    AND(const std::set<size_t>& INs, const std::set<size_t>& OUTs);

   public:
    nts::Tristate compute(std::size_t pin) override;
};

}  // namespace gate

#endif  // OOP_NANOTEKSPICE_2019_AND_HPP
