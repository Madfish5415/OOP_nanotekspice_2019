/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Link.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_LINK_HPP
#define OOP_NANOTEKSPICE_2019_LINK_HPP

#include <memory>

namespace nts {
class IComponent;
}

namespace nts {

class Link {
   public:
    typedef std::shared_ptr<Link> pointer;

   public:
    Link(IComponent *other, std::size_t otherPin);
    IComponent *getOther() const;
    size_t getOtherPin() const;

   private:
    IComponent *_other;
    const size_t _otherPin;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_LINK_HPP
