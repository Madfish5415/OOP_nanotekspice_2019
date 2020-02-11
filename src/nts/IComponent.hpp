/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** IComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
#define OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP

#include <cstddef>
#include <string>

namespace nts {

enum Tristate { UNDEFINED, TRUE, FALSE };

class IComponent {
   public:
    virtual ~IComponent() = default;
    virtual Tristate compute(std::size_t pin) = 0;
    virtual void setLink(
        std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
    virtual void dump() const = 0;
    virtual IComponent* clone() = 0;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
