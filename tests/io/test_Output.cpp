/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_Output.cpp
*/

#include <criterion/criterion.h>

#include "io/False.hpp"
#include "io/Output.hpp"
#include "io/True.hpp"

Test(Output, constructor)
{
    auto *io = new io::Output();

    delete io;
}

Test(Output, compute_link_false)
{
    auto *io = new io::Output();
    auto *io2 = new io::False();

    io->setLink(1, *io2, 1);

    nts::Tristate actual = io->compute(1);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete io;
    delete io2;
}

Test(Output, compute_link_true)
{
    auto *io = new io::Output();
    auto *io2 = new io::True();

    io->setLink(1, *io2, 1);

    nts::Tristate actual = io->compute(1);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete io;
    delete io2;
}

Test(Output, compute_unlink)
{
    auto *io = new io::Output();

    const std::string expected = "Output: Pin isn't linked";

    try {
        io->compute(1);
    } catch (std::exception &e) {
        cr_assert_str_eq(e.what(), expected.c_str());
    }

    delete io;
}