#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <dimension/dimension.hpp>

#include "arbitrary.hpp"

using dimension::millimeter;
using dimension::radius;

RC_GTEST_PROP(Add, Associative, (const radius& xs, const radius& ys, const radius& zs)) {
    RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
}

RC_GTEST_PROP(Add, Commutative, (const radius& xs, const radius& ys)) {
    RC_ASSERT((xs + ys) == (ys + xs));
}

RC_GTEST_PROP(Add, Neutral, (const radius& xs)) {
    RC_ASSERT((xs + radius(millimeter(0))) == xs);
}

TEST(Sub, Half) {
    radius xs(millimeter(2));
    radius ys(millimeter(1));
    EXPECT_EQ(xs - ys, ys);
}

TEST(Sub, Twice) {
    radius xs(millimeter(2));
    radius ys(millimeter(1));
    EXPECT_EQ(ys - xs, radius(millimeter(0)));
}

RC_GTEST_PROP(Sub, Neutral, (const radius& xs)) {
    RC_ASSERT((xs - radius(millimeter(0))) == xs);
}

RC_GTEST_PROP(Mul, Neutral, (const radius& xs)) {
    RC_ASSERT((xs * 1.0f) == xs);
    RC_ASSERT((1.0f * xs) == xs);
    RC_ASSERT((xs * 1.0 ) == xs);
    RC_ASSERT((1.0 * xs ) == xs);
}

RC_GTEST_PROP(Mul, Zero, (const radius& xs)) {
    radius zero(millimeter(0));

    RC_ASSERT((xs * 0.0f) == zero);
    RC_ASSERT((0.0f * xs) == zero);
    RC_ASSERT((xs * 0.0 ) == zero);
    RC_ASSERT((0.0 * xs ) == zero);
}

RC_GTEST_PROP(Mul, Commutative, (const radius& xs, const float& ys)) {
    RC_ASSERT((xs * ys) == (ys * xs));
}

RC_GTEST_PROP(Div, Neutral, (const radius& xs)) {
    RC_ASSERT((xs / 1.0f) == xs);
    RC_ASSERT((xs / 1.0 ) == xs);
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
