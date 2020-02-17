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

   class NOR : public gate::OR {
   public:
    NOR() = default;
    nts::Tristate operate(nts::Tristate t1, nts::Tristate t2) override;
};

}  // namespace gate

#endif  // OOP_NANOTEKSPICE_2019_NOR_HPP
