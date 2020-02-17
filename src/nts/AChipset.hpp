/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AChipset.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_ACHIPSET_HPP
#define OOP_NANOTEKSPICE_2019_ACHIPSET_HPP

#include <vector>

#include "AComponent.hpp"

namespace nts {

class AChipset : public AComponent {
   public:
    AChipset() = default;
    explicit AChipset(const std::string& value);
    AChipset(const AChipset& chipset);
    ~AChipset() override;
    AChipset& operator=(const AChipset& chipset);
    IComponent * clone() override;
    void addLogicGate(const std::vector<size_t>& inPins,
        const std::vector<size_t>& outPins, IComponent& logicGate);
    void removeLogicGate(const std::vector<size_t>& outPins);

   private:
    std::map<std::vector<size_t>, IComponent*> _logicGates;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_ACHIPSET_HPP
