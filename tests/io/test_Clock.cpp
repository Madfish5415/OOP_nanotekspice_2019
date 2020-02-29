/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_Clock.cpp
*/

#include <criterion/criterion.h>

#include "io/Clock.hpp"

Test(Clock, constructor)
{
    auto *io = new io::Clock();

    delete io;
}

Test(Clock, compute_0)
{
    auto *io = new io::Clock();

    io->setValue("0");

    nts::Tristate actual = io->compute(1);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete io;
}

Test(Clock, compute_1)
{
    auto *io = new io::Clock();

    io->setValue("1");

    nts::Tristate actual = io->compute(1);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete io;
}

Test(Clock, compute_unknown)
{
    auto *io = new io::Clock();

    io->setValue("Unknown");

    nts::Tristate actual = io->compute(1);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete io;
}

Test(Clock, multiple_compute_0)
{
    auto *io = new io::Clock();

    io->setValue("0");

    nts::Tristate actual1 = io->compute(1);
    nts::Tristate expected1 = nts::FALSE;

    cr_assert_eq(actual1, expected1);

    nts::Tristate actual2 = io->compute(1);
    nts::Tristate expected2 = nts::TRUE;

    cr_assert_eq(actual2, expected2);

    delete io;
}

Test(Clock, multiple_compute_1)
{
    auto *io = new io::Clock();

    io->setValue("1");

    nts::Tristate actual1 = io->compute(1);
    nts::Tristate expected1 = nts::TRUE;

    cr_assert_eq(actual1, expected1);

    nts::Tristate actual2 = io->compute(1);
    nts::Tristate expected2 = nts::FALSE;

    cr_assert_eq(actual2, expected2);

    delete io;
}

Test(Clock, multiple_compute_unknown)
{
    auto *io = new io::Clock();

    io->setValue("Unknown");

    nts::Tristate actual1 = io->compute(1);
    nts::Tristate expected1 = nts::UNDEFINED;

    cr_assert_eq(actual1, expected1);

    nts::Tristate actual2 = io->compute(1);
    nts::Tristate expected2 = nts::UNDEFINED;

    cr_assert_eq(actual2, expected2);

    delete io;
}
