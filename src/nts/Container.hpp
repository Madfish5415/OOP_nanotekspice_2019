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
   protected:
    typedef std::map<std::string, IComponent::pointer> Components;

   public:
    Container(const std::string &type, const std::set<size_t> &INs,
        const std::set<size_t> &OUTs);

   public:
    Tristate compute(std::size_t pin) override;
    void dump() override;
    void reset() override;

   public:
    void addComponent(const std::string &name, IComponent::pointer &component);
    const Components &getComponents() const;

   private:
    Components _components;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_CONTAINER_HPP
