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
