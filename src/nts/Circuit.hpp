/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_CIRCUIT_HPP
#define OOP_NANOTEKSPICE_2019_CIRCUIT_HPP

#include "Container.hpp"

namespace nts {

class Circuit : public Container {
   public:
    Circuit();

   public:
    void display();
    void input(const std::string &name, const std::string &value);
    void simulate();

   private:
    std::map<std::string, Tristate> _results;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_CIRCUIT_HPP
