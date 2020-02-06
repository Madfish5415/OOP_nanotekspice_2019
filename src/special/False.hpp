/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_FALSE_HPP
#define OOP_NANOTEKSPICE_2019_FALSE_HPP

#include "../nts/AComponent.hpp"

namespace special {

class False : public nts::AComponent {
   public:
    False() = default;
    nts::Tristate compute(std::size_t) override;
};

}  // namespace special

#endif  // OOP_NANOTEKSPICE_2019_FALSE_HPP
