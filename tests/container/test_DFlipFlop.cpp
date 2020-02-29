/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_DFlipFlop.cpp
*/

#include <criterion/criterion.h>

#include <iostream>

#include "../io/mock/Undefined.hpp"
#include "container/DFlipFlop.hpp"
#include "io/False.hpp"
#include "io/True.hpp"

static std::string stringFromState(nts::Tristate state)
{
    switch (state) {
        case nts::UNDEFINED:
            return std::string("UNDEFINED");
        case nts::FALSE:
            return std::string("FALSE");
        case nts::TRUE:
            return std::string("TRUE");
    }

    return std::string("UNKNOWN");
}

Test(DFlipFlop, constructor)
{
    auto *container = new container::DFlipFlop();

    delete container;
}

Test(DFlipFlop, compute_false_false_false_false)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::True(); // clock
    auto *io2 = new io::False(); // reset
    auto *io3 = new io::False(); // data
    auto *io4 = new io::False(); // set

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::FALSE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::TRUE;

    std::cout << "actual1: " << stringFromState(actual1) << std::endl;
    std::cout << "actual2: " << stringFromState(actual2) << std::endl;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}
