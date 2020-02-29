/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NAND.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_NAND_HPP
#define OOP_NANOTEKSPICE_2019_NAND_HPP

#include "nts/Container.hpp"

namespace container {

class NAND : public nts::Container {
   public:
    NAND(const std::set<size_t>& INs, const std::set<size_t>& OUTs);
};

}  // namespace container

#endif  // OOP_NANOTEKSPICE_2019_NAND_HPP
