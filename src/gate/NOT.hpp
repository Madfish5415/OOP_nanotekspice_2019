/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NOT.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_NOT_HPP
#define OOP_NANOTEKSPICE_2019_NOT_HPP

#include "../nts/ALogicGate.hpp"

namespace gate {

class NOT : public nts::ALogicGate {
   public:
    NOT() = default;
    nts::Tristate operate(nts::Tristate t1, nts::Tristate t2) override;
};

}  // namespace gate

#endif  // OOP_NANOTEKSPICE_2019_NOT_HPP
