/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_C4001.cpp
*/

#include <criterion/criterion.h>

#include "../io/mock/Undefined.hpp"
#include "chipset/C4001.hpp"
#include "io/False.hpp"
#include "io/True.hpp"

Test(C4001, constructor)
{
    auto *chipset = new chipset::C4001();

    delete chipset;
}

Test(C4001, compute_1_false_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::False();
    auto *io2 = new io::False();

    chipset->setLink(1, *io1, 1);
    chipset->setLink(2, *io2, 1);

    nts::Tristate actual = chipset->compute(3);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_1_true_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::True();
    auto *io2 = new io::False();

    chipset->setLink(1, *io1, 1);
    chipset->setLink(2, *io2, 1);

    nts::Tristate actual = chipset->compute(3);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_1_true_true)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::True();
    auto *io2 = new io::True();

    chipset->setLink(1, *io1, 1);
    chipset->setLink(2, *io2, 1);

    nts::Tristate actual = chipset->compute(3);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_1_undefined_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::False();

    chipset->setLink(1, *io1, 1);
    chipset->setLink(2, *io2, 1);

    nts::Tristate actual = chipset->compute(3);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_1_undefined_true)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::True();

    chipset->setLink(1, *io1, 1);
    chipset->setLink(2, *io2, 1);

    nts::Tristate actual = chipset->compute(3);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_2_false_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::False();
    auto *io2 = new io::False();

    chipset->setLink(5, *io1, 1);
    chipset->setLink(6, *io2, 1);

    nts::Tristate actual = chipset->compute(4);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_2_true_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::True();
    auto *io2 = new io::False();

    chipset->setLink(5, *io1, 1);
    chipset->setLink(6, *io2, 1);

    nts::Tristate actual = chipset->compute(4);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_2_true_true)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::True();
    auto *io2 = new io::True();

    chipset->setLink(5, *io1, 1);
    chipset->setLink(6, *io2, 1);

    nts::Tristate actual = chipset->compute(4);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_2_undefined_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::False();

    chipset->setLink(5, *io1, 1);
    chipset->setLink(6, *io2, 1);

    nts::Tristate actual = chipset->compute(4);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_2_undefined_true)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::True();

    chipset->setLink(5, *io1, 1);
    chipset->setLink(6, *io2, 1);

    nts::Tristate actual = chipset->compute(4);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_3_false_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::False();
    auto *io2 = new io::False();

    chipset->setLink(8, *io1, 1);
    chipset->setLink(9, *io2, 1);

    nts::Tristate actual = chipset->compute(10);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_3_true_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::True();
    auto *io2 = new io::False();

    chipset->setLink(8, *io1, 1);
    chipset->setLink(9, *io2, 1);

    nts::Tristate actual = chipset->compute(10);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_3_true_true)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::True();
    auto *io2 = new io::True();

    chipset->setLink(8, *io1, 1);
    chipset->setLink(9, *io2, 1);

    nts::Tristate actual = chipset->compute(10);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_3_undefined_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::False();

    chipset->setLink(8, *io1, 1);
    chipset->setLink(9, *io2, 1);

    nts::Tristate actual = chipset->compute(10);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_3_undefined_true)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::True();

    chipset->setLink(8, *io1, 1);
    chipset->setLink(9, *io2, 1);

    nts::Tristate actual = chipset->compute(10);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_4_false_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::False();
    auto *io2 = new io::False();

    chipset->setLink(12, *io1, 1);
    chipset->setLink(13, *io2, 1);

    nts::Tristate actual = chipset->compute(11);
    nts::Tristate expected = nts::TRUE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_4_true_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::True();
    auto *io2 = new io::False();

    chipset->setLink(12, *io1, 1);
    chipset->setLink(13, *io2, 1);

    nts::Tristate actual = chipset->compute(11);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_4_true_true)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::True();
    auto *io2 = new io::True();

    chipset->setLink(12, *io1, 1);
    chipset->setLink(13, *io2, 1);

    nts::Tristate actual = chipset->compute(11);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_4_undefined_false)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::False();

    chipset->setLink(12, *io1, 1);
    chipset->setLink(13, *io2, 1);

    nts::Tristate actual = chipset->compute(11);
    nts::Tristate expected = nts::UNDEFINED;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}

Test(C4001, compute_4_undefined_true)
{
    auto *chipset = new chipset::C4001();
    auto *io1 = new io::mock::Undefined();
    auto *io2 = new io::True();

    chipset->setLink(12, *io1, 1);
    chipset->setLink(13, *io2, 1);

    nts::Tristate actual = chipset->compute(11);
    nts::Tristate expected = nts::FALSE;

    cr_assert_eq(actual, expected);

    delete chipset;
    delete io1;
    delete io2;
}
