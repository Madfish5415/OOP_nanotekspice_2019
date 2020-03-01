/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NOR.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_NOR_HPP
#define OOP_NANOTEKSPICE_2019_NOR_HPP

#include "nts/Container.hpp"

namespace container {

class NOR : public nts::Container {
   public:
    NOR(const std::set<size_t>& INs, const std::set<size_t>& OUTs);
};

}  // namespace container

#endif  // OOP_NANOTEKSPICE_2019_NOR_HPP
