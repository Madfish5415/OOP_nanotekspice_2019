/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_CIRCUIT_HPP
#define OOP_NANOTEKSPICE_2019_CIRCUIT_HPP

#include <map>
#include <string>

#include "AComponent.hpp"

namespace nts {

class Circuit : public AComponent {
   public:
    Circuit() = default;
    void addComponent(const std::string& name, IComponent& component);
    void removeComponent(const std::string& name);
    IComponent& getComponent(const std::string& name);
    void display();
    void simulate();

   private:
    std::map<std::string, IComponent*> _components;
    std::map<std::string, Tristate> _results;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_CIRCUIT_HPP
