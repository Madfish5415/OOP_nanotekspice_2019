/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_FACTORY_HPP
#define OOP_NANOTEKSPICE_2019_FACTORY_HPP

#include <functional>
#include <map>

#include "IComponent.hpp"

namespace nts {

typedef std::function<IComponent::pointer(const std::string&)>
    Constructor;

class Factory {
   public:
    static IComponent::pointer Create(
        const std::string& type, const std::string& value = "");
    static void Register(
        const std::string& type, const Constructor& constructor);

   private:
    static std::map<std::string, Constructor>& constructors();
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_FACTORY_HPP
