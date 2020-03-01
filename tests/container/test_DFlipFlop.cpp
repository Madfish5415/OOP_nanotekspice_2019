/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_DFlipFlop.cpp
*/

#include <criterion/criterion.h>

#include "../io/mock/Undefined.hpp"
#include "container/DFlipFlop.hpp"
#include "io/False.hpp"
#include "io/True.hpp"

Test(DFlipFlop, constructor)
{
    auto *container = new container::DFlipFlop();

    delete container;
}

Test(DFlipFlop, compute_true_false_false_false)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::True();
    auto *io2 = new io::False();
    auto *io3 = new io::False();
    auto *io4 = new io::False();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::TRUE; // FALSE
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::FALSE; // TRUE

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_true_false_true_false)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::True();
    auto *io2 = new io::False();
    auto *io3 = new io::True();
    auto *io4 = new io::False();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::TRUE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::FALSE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_false_false_false_false)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::False();
    auto *io2 = new io::False();
    auto *io3 = new io::False();
    auto *io4 = new io::False();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::UNDEFINED;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::UNDEFINED;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_false_false_true_false)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::False();
    auto *io2 = new io::False();
    auto *io3 = new io::True();
    auto *io4 = new io::False();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::UNDEFINED;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::UNDEFINED;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_false_true_false_false)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::False();
    auto *io2 = new io::True();
    auto *io3 = new io::False();
    auto *io4 = new io::False();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::FALSE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::TRUE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_true_true_false_false)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::True();
    auto *io2 = new io::True();
    auto *io3 = new io::False();
    auto *io4 = new io::False();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::FALSE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::TRUE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_false_true_true_false)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::False();
    auto *io2 = new io::True();
    auto *io3 = new io::True();
    auto *io4 = new io::False();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::FALSE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::TRUE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_true_true_true_false)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::True();
    auto *io2 = new io::True();
    auto *io3 = new io::True();
    auto *io4 = new io::False();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::FALSE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::TRUE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_false_false_false_true)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::False();
    auto *io2 = new io::False();
    auto *io3 = new io::False();
    auto *io4 = new io::True();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::TRUE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::FALSE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_true_false_false_true)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::True();
    auto *io2 = new io::False();
    auto *io3 = new io::False();
    auto *io4 = new io::True();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::TRUE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::FALSE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_false_false_true_true)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::False();
    auto *io2 = new io::False();
    auto *io3 = new io::True();
    auto *io4 = new io::True();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::TRUE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::FALSE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_true_false_true_true)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::True();
    auto *io2 = new io::False();
    auto *io3 = new io::True();
    auto *io4 = new io::True();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::TRUE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::FALSE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_false_true_false_true)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::False();
    auto *io2 = new io::True();
    auto *io3 = new io::False();
    auto *io4 = new io::True();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::TRUE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::TRUE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_true_true_false_true)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::True();
    auto *io2 = new io::True();
    auto *io3 = new io::False();
    auto *io4 = new io::True();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::TRUE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::TRUE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_false_true_true_true)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::False();
    auto *io2 = new io::True();
    auto *io3 = new io::True();
    auto *io4 = new io::True();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::TRUE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::TRUE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}

Test(DFlipFlop, compute_true_true_true_true)
{
    auto *container = new container::DFlipFlop();
    auto *io1 = new io::True();
    auto *io2 = new io::True();
    auto *io3 = new io::True();
    auto *io4 = new io::True();

    container->setLink(1, *io1, 1);
    container->setLink(2, *io2, 1);
    container->setLink(3, *io3, 1);
    container->setLink(4, *io4, 1);

    nts::Tristate actual1 = container->compute(5);
    nts::Tristate expected1 = nts::TRUE;
    nts::Tristate actual2 = container->compute(6);
    nts::Tristate expected2 = nts::TRUE;

    cr_assert_eq(actual1, expected1);
    cr_assert_eq(actual2, expected2);

    delete container;
    delete io1;
    delete io2;
    delete io3;
    delete io4;
}