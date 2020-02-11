/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** ALogicGate.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_ALOGICGATE_HPP
#define OOP_NANOTEKSPICE_2019_ALOGICGATE_HPP

#include "AComponent.hpp"

namespace nts {

class ALogicGate : public AComponent {
   public:
    ALogicGate() = default;
    ALogicGate(const ALogicGate& logicGate);
    ~ALogicGate() override = default;
    ALogicGate& operator=(const ALogicGate& logicGate);
    Tristate compute(std::size_t) override;

   protected:
    virtual nts::Tristate operate(nts::Tristate t1, nts::Tristate t2) = 0;
};

}  // namespace nts

#endif  // OOP_NANOTEKSPICE_2019_ALOGICGATE_HPP
