/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_True.cpp
*/


#include <criterion/criterion.h>

#include "io/True.hpp"

Test(True, constructor)
{
    auto *io = new io::True();

    delete io;
}

Test(True, compute)
{
    auto *io = new io::True();

    nts::Tristate actual = io->compute(1);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete io;
}
