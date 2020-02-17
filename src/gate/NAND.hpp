/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NAND.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_NAND_HPP
#define OOP_NANOTEKSPICE_2019_NAND_HPP

#include "AND.hpp"

namespace gate {

class NAND : public AND {
   public:
    NAND() = default;
    nts::Tristate operate(nts::Tristate t1, nts::Tristate t2) override;
};

}  // namespace gate

#endif  // OOP_NANOTEKSPICE_2019_NAND_HPP
