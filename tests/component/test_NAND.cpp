/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_NAND.cpp
*/

#include <criterion/criterion.h>

#include "../io/mock/Undefined.hpp"
#include "component/NAND.hpp"
#include "io/False.hpp"
#include "io/True.hpp"

Test(NAND, constructor_2_pin)
{
    auto *component = new component::NAND({1, 2}, {3});

    delete component;
}

Test(NAND, compute_2_pin_false_false)
{
    auto *component = new component::NAND({1, 2}, {3});
    auto *io1 = new io::False();
    auto *io2 = new io::False();

    component->setLink(1, *io1, 1);
    component->setLink(2, *io2, 1);

    nts::Tristate actual = component->compute(3);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete component;
    delete io1;
    delete io2;
}

Test(NAND, compute_2_pin_true_false)
{
    auto *component = new component::NAND({1, 2}, {3});
    auto *io1 = new io::True();
    auto *io2 = new io::False();

    component->setLink(1, *io1, 1);
    component->setLink(2, *io2, 1);

    nts::Tristate actual = component->compute(3);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete component;
    delete io1;
    delete io2;
}

Test(NAND, compute_2_pin_true_true)
{
    auto *component = new component::NAND({1, 2}, {3});
    auto *io1 = new io::True();
    auto *io2 = new io::True();

    component->setLink(1, *io1, 1);
    component->setLink(2, *io2, 1);

    nts::Tristate actual = component->compute(3);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete component;
    delete io1;
    delete io2;
}

Test(NAND, compute_2_pin_undefined_false)
{
    auto *component = new component::NAND({1, 2}, {3});
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::False();

    component->setLink(1, *io1, 1);
    component->setLink(2, *io2, 1);

    nts::Tristate actual = component->compute(3);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete component;
    delete io1;
    delete io2;
}

Test(NAND, compute_2_pin_undefined_true)
{
    auto *component = new component::NAND({1, 2}, {3});
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::True();

    component->setLink(1, *io1, 1);
    component->setLink(2, *io2, 1);

    nts::Tristate actual = component->compute(3);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete component;
    delete io1;
    delete io2;
}
