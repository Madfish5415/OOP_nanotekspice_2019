/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** IComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
#define OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP

#include <cstddef>
#include <set>
#include <string>

namespace nts {

class IComponent;

enum Tristate {
    UNDEFINED = (-true),
    FALSE = false,
    TRUE = true,
};

struct Link {
    IComponent* other;
    std::size_t otherPin;
};

class IComponent {
   public:
    virtual ~IComponent() = default;

   public:
    virtual Tristate compute(std::size_t pin) = 0;
    virtual void dump() = 0;
    virtual void reset() = 0;
    virtual const std::string& getType() const = 0;
    virtual const std::set<size_t>& getINs() const = 0;
    virtual const std::set<size_t>& getOUTs() const = 0;
    virtual const Link& getLink(std::size_t pin) const = 0;
    virtual void setLink(
        std::size_t pin, IComponent& other, size_t otherPin) = 0;
    virtual const std::string& getValue() const = 0;
    virtual void setValue(const std::string& value) = 0;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
