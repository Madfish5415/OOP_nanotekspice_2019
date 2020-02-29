/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_False.cpp
*/

#include <criterion/criterion.h>

#include "io/False.hpp"

Test(False, constructor)
{
    auto *io = new io::False();

    delete io;
}

Test(False, compute)
{
    auto *io = new io::False();

    nts::Tristate actual = io->compute(1);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete io;
}

Test(False, multiple_compute)
{
    auto *io = new io::False();

    nts::Tristate actual1 = io->compute(1);
    nts::Tristate expected1 = nts::FALSE;

    cr_assert_eq(actual1, expected1);

    nts::Tristate actual2 = io->compute(1);
    nts::Tristate expected2 = nts::FALSE;

    cr_assert_eq(actual2, expected2);

    delete io;
}
