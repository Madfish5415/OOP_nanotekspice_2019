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
    NAND(const std::set<size_t>& INs, const std::set<size_t>& OUTs);

   public:
    nts::Tristate compute(std::size_t pin) override;
};

}  // namespace gate

#endif  // OOP_NANOTEKSPICE_2019_NAND_HPP
