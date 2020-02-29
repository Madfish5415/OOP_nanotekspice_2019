/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_NOT.cpp
*/

#include <criterion/criterion.h>

#include "../io/mock/Undefined.hpp"
#include "gate/NOT.hpp"
#include "io/False.hpp"
#include "io/True.hpp"

Test(NOT, constructNOT_2_pin)
{
    auto *gate = new gate::NOT({1}, {2});

    delete gate;
}

Test(NOT, compute_false)
{
    auto *gate = new gate::NOT({1}, {2});
    auto *io = new io::False();

    gate->setLink(1, *io, 1);

    nts::Tristate actual = gate->compute(2);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete gate;
    delete io;
}

Test(NOT, compute_true)
{
    auto *gate = new gate::NOT({1}, {2});
    auto *io = new io::True();

    gate->setLink(1, *io, 1);

    nts::Tristate actual = gate->compute(2);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete gate;
    delete io;
}

Test(NOT, compute_undefined)
{
    auto *gate = new gate::NOT({1}, {2});
    auto *io = new io::mock::Undefined();

    gate->setLink(1, *io, 1);

    nts::Tristate actual = gate->compute(2);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete gate;
    delete io;
}
