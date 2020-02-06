/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_TRUE_HPP
#define OOP_NANOTEKSPICE_2019_TRUE_HPP

#include "../nts/AComponent.hpp"

namespace special {

class True : public nts::AComponent {
   public:
    True() = default;
    nts::Tristate compute(std::size_t) override;
};

}  // namespace special

#endif  // OOP_NANOTEKSPICE_2019_TRUE_HPP
