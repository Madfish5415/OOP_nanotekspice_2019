/*
** EPITECH PROJECT, 2020
** OOP_naC4069ekspice_2019
** File description:
** test_C4069.cpp
*/

#include <criterion/criterion.h>

#include "../io/mock/Undefined.hpp"
#include "chipset/C4069.hpp"
#include "io/False.hpp"
#include "io/True.hpp"

Test(C4069, constructor)
{
    auto *chipset = new chipset::C4069();

    delete chipset;
}

Test(C4069, compute_1_false)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::False();

    chipset->setLink(1, *io, 1);

    nts::Tristate actual = chipset->compute(2);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_1_true)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::True();

    chipset->setLink(1, *io, 1);

    nts::Tristate actual = chipset->compute(2);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_1_undefined)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::mock::Undefined();

    chipset->setLink(1, *io, 1);

    nts::Tristate actual = chipset->compute(2);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_2_false)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::False();

    chipset->setLink(3, *io, 1);

    nts::Tristate actual = chipset->compute(4);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_2_true)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::True();

    chipset->setLink(3, *io, 1);

    nts::Tristate actual = chipset->compute(4);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_2_undefined)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::mock::Undefined();

    chipset->setLink(3, *io, 1);

    nts::Tristate actual = chipset->compute(4);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_3_false)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::False();

    chipset->setLink(5, *io, 1);

    nts::Tristate actual = chipset->compute(6);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_3_true)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::True();

    chipset->setLink(5, *io, 1);

    nts::Tristate actual = chipset->compute(6);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_3_undefined)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::mock::Undefined();

    chipset->setLink(5, *io, 1);

    nts::Tristate actual = chipset->compute(6);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_4_false)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::False();

    chipset->setLink(9, *io, 1);

    nts::Tristate actual = chipset->compute(8);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_4_true)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::True();

    chipset->setLink(9, *io, 1);

    nts::Tristate actual = chipset->compute(8);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_4_undefined)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::mock::Undefined();

    chipset->setLink(9, *io, 1);

    nts::Tristate actual = chipset->compute(8);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_5_false)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::False();

    chipset->setLink(11, *io, 1);

    nts::Tristate actual = chipset->compute(10);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_5_true)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::True();

    chipset->setLink(11, *io, 1);

    nts::Tristate actual = chipset->compute(10);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_5_undefined)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::mock::Undefined();

    chipset->setLink(11, *io, 1);

    nts::Tristate actual = chipset->compute(10);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_6_false)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::False();

    chipset->setLink(13, *io, 1);

    nts::Tristate actual = chipset->compute(12);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_6_true)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::True();

    chipset->setLink(13, *io, 1);

    nts::Tristate actual = chipset->compute(12);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}

Test(C4069, compute_6_undefined)
{
    auto *chipset = new chipset::C4069();
    auto *io = new io::mock::Undefined();

    chipset->setLink(13, *io, 1);

    nts::Tristate actual = chipset->compute(12);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io;
}
