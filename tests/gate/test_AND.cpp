/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_AND.cpp
*/

#include <criterion/criterion.h>

#include "../io/mock/Undefined.hpp"
#include "gate/AND.hpp"
#include "io/False.hpp"
#include "io/True.hpp"

Test(AND, constructor_2_pin)
{
    auto *gate = new gate::AND({1, 2}, {3});

    delete gate;
}

Test(AND, compute_2_pin_false_false)
{
    auto *gate = new gate::AND({1, 2}, {3});
    auto *io1 = new io::False();
    auto *io2 = new io::False();

    gate->setLink(1, *io1, 1);
    gate->setLink(2, *io2, 1);

    nts::Tristate actual = gate->compute(3);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete gate;
    delete io1;
    delete io2;
}

Test(AND, compute_2_pin_true_false)
{
    auto *gate = new gate::AND({1, 2}, {3});
    auto *io1 = new io::True();
    auto *io2 = new io::False();

    gate->setLink(1, *io1, 1);
    gate->setLink(2, *io2, 1);

    nts::Tristate actual = gate->compute(3);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete gate;
    delete io1;
    delete io2;
}

Test(AND, compute_2_pin_true_true)
{
    auto *gate = new gate::AND({1, 2}, {3});
    auto *io1 = new io::True();
    auto *io2 = new io::True();

    gate->setLink(1, *io1, 1);
    gate->setLink(2, *io2, 1);

    nts::Tristate actual = gate->compute(3);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete gate;
    delete io1;
    delete io2;
}

Test(AND, compute_2_pin_undefined_false)
{
    auto *gate = new gate::AND({1, 2}, {3});
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::False();

    gate->setLink(1, *io1, 1);
    gate->setLink(2, *io2, 1);

    nts::Tristate actual = gate->compute(3);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete gate;
    delete io1;
    delete io2;
}

Test(AND, compute_2_pin_undefined_true)
{
    auto *gate = new gate::AND({1, 2}, {3});
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::True();

    gate->setLink(1, *io1, 1);
    gate->setLink(2, *io2, 1);

    nts::Tristate actual = gate->compute(3);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete gate;
    delete io1;
    delete io2;
}
