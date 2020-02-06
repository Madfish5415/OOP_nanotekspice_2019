/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AChipset.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_ACHIPSET_HPP
#define OOP_NANOTEKSPICE_2019_ACHIPSET_HPP

#include "AComponent.hpp"

namespace nts {

class AChipset : public AComponent {
   public:
    AChipset() = default;

   protected:
    void addLogicGate(const std::vector<size_t>& inPins,
        const std::vector<size_t>& outPins, IComponent& logicGate);
    void removeLogicGate(std::vector<size_t> outPins);
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_ACHIPSET_HPP
