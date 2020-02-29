/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NOR.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_NOR_HPP
#define OOP_NANOTEKSPICE_2019_NOR_HPP

#include "OR.hpp"

namespace gate {

class NOR : public OR {
   public:
    NOR(const std::set<size_t>& INs, const std::set<size_t>& OUTs);

   public:
    nts::Tristate compute(std::size_t pin) override;
};

}  // namespace gate

#endif  // OOP_NANOTEKSPICE_2019_NOR_HPP
