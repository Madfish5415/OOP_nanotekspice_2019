/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** XOR.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_XOR_HPP
#define OOP_NANOTEKSPICE_2019_XOR_HPP

#include "../nts/ALogicGate.hpp"

namespace gate {

class XOR : public nts::ALogicGate {
   public:
    XOR() = default;
    nts::Tristate operate(nts::Tristate t1, nts::Tristate t2) override;
};

}  // namespace gate

#endif  // OOP_NANOTEKSPICE_2019_XOR_HPP
