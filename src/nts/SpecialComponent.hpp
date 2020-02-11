/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SpecialComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_SPECIALCOMPONENT_HPP
#define OOP_NANOTEKSPICE_2019_SPECIALCOMPONENT_HPP

#include "AComponent.hpp"

namespace nts {

class SpecialComponent : public AComponent {
   public:
    SpecialComponent() = default;
    explicit SpecialComponent(Tristate state);
    SpecialComponent(const SpecialComponent& specialComponent);
    ~SpecialComponent() override = default;
    SpecialComponent& operator=(const SpecialComponent& specialComponent);
    Tristate compute(std::size_t pin) override;
    IComponent* clone() override;

   protected:
    Tristate _state = nts::UNDEFINED;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_SPECIALCOMPONENT_HPP
