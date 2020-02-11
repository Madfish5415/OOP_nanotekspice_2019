/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OR.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_OR_HPP
#define OOP_NANOTEKSPICE_2019_OR_HPP

#include "../nts/ALogicGate.hpp"

namespace gate {

class OR : public nts::ALogicGate {
   public:
    OR() = default;
    nts::Tristate operate(nts::Tristate t1, nts::Tristate t2) override;
};

}  // namespace gate

#endif  // OOP_NANOTEKSPICE_2019_OR_HPP
