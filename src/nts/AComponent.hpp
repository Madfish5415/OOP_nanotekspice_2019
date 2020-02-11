/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_COMPONENT_HPP
#define OOP_NANOTEKSPICE_2019_COMPONENT_HPP

#include <map>
#include <string>

#include "IComponent.hpp"

namespace nts {

class AComponent : public IComponent {
   public:
    AComponent() = default;
    explicit AComponent(const std::string& value);
    AComponent(const AComponent& component);
    ~AComponent() override = default;
    AComponent& operator=(const AComponent& component);
    Tristate compute(std::size_t pin) override;
    void setLink(
        std::size_t pin, IComponent& other, std::size_t otherPin) override;
    void dump() const override;
    IComponent* clone() override;

   protected:
    std::string _value;
    std::map<size_t, std::pair<IComponent*, size_t>> _links;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_COMPONENT_HPP
