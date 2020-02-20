/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_ACOMPONENT_HPP
#define OOP_NANOTEKSPICE_2019_ACOMPONENT_HPP

#include <map>
#include <set>

#include "IComponent.hpp"

namespace nts {

class AComponent : public IComponent {
   public:
    AComponent(const std::string &type, const std::set<size_t> &INs,
        const std::set<size_t> &OUTs);

   public:
    Tristate compute(std::size_t pin) override = 0;
    void dump() override;
    void reset() override;
    const std::string &getType() const override;
    const std::set<std::size_t> &getINs() const override;
    const std::set<std::size_t> &getOUTs() const override;
    const Link* getLink(std::size_t pin) const override;
    void setLink(std::size_t pin, IComponent& other, size_t otherPin) override;
    const std::string &getValue() const override;
    void setValue(const std::string &value) override;

   protected:
    const std::string _type;
    std::set<std::size_t> _INs;
    std::set<std::size_t> _OUTs;
    std::map<std::size_t, Link *> _pins;
    std::map<std::size_t, Tristate> _states;
    std::string _value;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_ACOMPONENT_HPP
