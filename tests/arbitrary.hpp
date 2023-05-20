#ifndef DIMENSION_ARBITRARY_HPP__
#define DIMENSION_ARBITRARY_HPP__

#include <rapidcheck/gtest.h>
#include <dimension/dimension.hpp>

namespace rc {
    template <>
    struct Arbitrary<dimension::millimeter> {
        static Gen<dimension::millimeter>
        arbitrary() {
            return gen::construct<dimension::millimeter>(
                    gen::inRange<std::uint16_t>(0, std::numeric_limits<std::uint16_t>::max())
                    );
        }
    };

    template <>
    struct Arbitrary<dimension::radius> {
        static Gen<dimension::radius>
        arbitrary() {
            return gen::construct<dimension::radius>(
                    gen::arbitrary<dimension::millimeter>()
                    );
        }
    };
} // namespace rc

#endif // DIMENSION_ARBITRARY_HPP__
