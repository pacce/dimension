#ifndef DIMENSION_RADIUS_HPP__
#define DIMENSION_RADIUS_HPP__

#include <ostream>
#include "dimension-millimeter.hpp"

namespace dimension {
    class radius {
        public:
            explicit radius() : value_(0) {}
            explicit radius(const millimeter& value) : value_(value) {}

            explicit operator float() const     { return static_cast<float>(value_); }
            explicit operator double() const    { return static_cast<double>(value_); }

            friend std::ostream&
            operator<<(std::ostream& os, const radius& r) {
                os << r.value_;
                return os;
            }

            auto operator<=>(const radius&) const = default;

            friend radius
            operator+(const radius& lhs, const radius& rhs) {
                return radius(lhs.value_ + rhs.value_);
            }

            friend radius
            operator-(const radius& lhs, const radius& rhs) {
                return radius(lhs.value_ - rhs.value_);
            }

            friend radius
            operator*(const radius& unit, const float& scalar) {
                return radius(unit.value_ * scalar);
            }

            friend radius
            operator*(const float& scalar, const radius& unit) {
                return radius(unit.value_ * scalar);
            }

            friend radius
            operator/(const radius& unit, const float& scalar) {
                return radius(unit.value_ / scalar);
            }

            friend radius
            operator/(const radius& unit, const double& scalar) {
                return radius(unit.value_ / scalar);
            }
        private:
            millimeter value_;
    };
} // namespace

#endif // DIMENSION_RADIUS_HPP__
