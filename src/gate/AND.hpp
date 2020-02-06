/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AND.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_AND_HPP
#define OOP_NANOTEKSPICE_2019_AND_HPP

#include "../nts/ALogicGate.hpp"

namespace gate {

class AND : public nts::ALogicGate {
   public:
    AND() = default;
    nts::Tristate operate(nts::Tristate t1, nts::Tristate t2) override;
};

}  // namespace gate

#endif  // OOP_NANOTEKSPICE_2019_AND_HPP
