#ifndef DIMENSION_WIDTH_HPP__
#define DIMENSION_WIDTH_HPP__

#include <ostream>
#include "dimension-millimeter.hpp"

namespace dimension {
    class width {
        public:
            explicit width() {}
            explicit width(const millimeter& value) : value_(value) {}

            explicit operator float() const     { return static_cast<float>(value_); }
            explicit operator double() const    { return static_cast<double>(value_); }

            friend std::ostream&
            operator<<(std::ostream& os, const width& r) {
                os << r.value_;
                return os;
            }
        private:
            millimeter value_;
    };
} // namespace

#endif // DIMENSION_WIDTH_HPP__
