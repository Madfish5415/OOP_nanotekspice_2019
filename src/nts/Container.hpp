/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Container.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_CONTAINER_HPP
#define OOP_NANOTEKSPICE_2019_CONTAINER_HPP

#include "AComponent.hpp"

namespace nts {

class Container : public AComponent {
   public:
    Container(const std::string &type, const std::set<size_t> &INs,
        const std::set<size_t> &OUTs);
    Tristate compute(std::size_t pin) override;
    void dump() override;
    void reset() override;

   public:
    void addComponent(const std::string &name, IComponent &component);
    const std::map<std::string, IComponent *> &getComponents() const;
    void removeComponent(const std::string &name);

   protected:
    std::map<std::string, IComponent *> _components;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_CONTAINER_HPP
