#ifndef DIMENSION_RADIUS_HPP__
#define DIMENSION_RADIUS_HPP__

#include <ostream>
#include "dimension-millimeter.hpp"

namespace dimension {
    class radius {
        public:
            explicit radius() {}
            explicit radius(const millimeter& value) : value_(value) {}

            explicit operator float() const     { return static_cast<float>(value_); }
            explicit operator double() const    { return static_cast<double>(value_); }

            friend std::ostream&
            operator<<(std::ostream& os, const radius& r) {
                os << r.value_;
                return os;
            }
        private:
            millimeter value_;
    };
} // namespace

#endif // DIMENSION_RADIUS_HPP__
