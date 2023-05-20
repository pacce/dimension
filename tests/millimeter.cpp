#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <dimension/dimension.hpp>

#include "arbitrary.hpp"

using dimension::millimeter;

RC_GTEST_PROP(Add, Associative, (const millimeter& xs, const millimeter& ys, const millimeter& zs)) {
    RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
}

RC_GTEST_PROP(Add, Commutative, (const millimeter& xs, const millimeter& ys)) {
    RC_ASSERT((xs + ys) == (ys + xs));
}

RC_GTEST_PROP(Add, Neutral, (const millimeter& xs)) {
    RC_ASSERT((xs + millimeter(0)) == xs);
}

TEST(Sub, Half) {
    millimeter xs(2);
    millimeter ys(1);
    EXPECT_EQ(xs - ys, ys);
}

TEST(Sub, Twice) {
    millimeter xs(2);
    millimeter ys(1);
    EXPECT_EQ(ys - xs, millimeter(0));
}

RC_GTEST_PROP(Sub, Neutral, (const millimeter& xs)) {
    RC_ASSERT((xs - millimeter(0)) == xs);
}

RC_GTEST_PROP(Mul, Neutral, (const millimeter& xs)) {
    RC_ASSERT((xs * 1.0f) == xs);
    RC_ASSERT((1.0f * xs) == xs);
    RC_ASSERT((xs * 1.0 ) == xs);
    RC_ASSERT((1.0 * xs ) == xs);
}

RC_GTEST_PROP(Mul, Zero, (const millimeter& xs)) {
    millimeter zero(0);

    RC_ASSERT((xs * 0.0f) == zero);
    RC_ASSERT((0.0f * xs) == zero);
    RC_ASSERT((xs * 0.0 ) == zero);
    RC_ASSERT((0.0 * xs ) == zero);
}

RC_GTEST_PROP(Mul, Commutative, (const millimeter& xs, const float& ys)) {
    RC_ASSERT((xs * ys) == (ys * xs));
}

RC_GTEST_PROP(Div, Neutral, (const millimeter& xs)) {
    RC_ASSERT((xs / 1.0f) == xs);
    RC_ASSERT((xs / 1.0 ) == xs);
}

TEST(Literal, Millimeter) {
    using namespace dimension::literals;
    EXPECT_EQ(millimeter(10), 10_mm);
    EXPECT_EQ(millimeter(10), 10.5_mm);
}

TEST(Literal, Centimeter) {
    using namespace dimension::literals;
    EXPECT_EQ(millimeter(10), 1_cm);
    EXPECT_EQ(millimeter(15), 1.5_cm);
}

TEST(Literal, Meter) {
    using namespace dimension::literals;
    EXPECT_EQ(millimeter(100), 1_m);
    EXPECT_EQ(millimeter(150), 1.50_m);
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
