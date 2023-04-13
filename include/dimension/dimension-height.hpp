#ifndef DIMENSION_HEIGHT_HPP__
#define DIMENSION_HEIGHT_HPP__

#include <ostream>
#include "dimension-millimeter.hpp"

namespace dimension {
    class height {
        public:
            explicit height() {}
            explicit height(const millimeter& value) : value_(value) {}

            explicit operator float() const     { return static_cast<float>(value_); }
            explicit operator double() const    { return static_cast<double>(value_); }

            friend std::ostream&
            operator<<(std::ostream& os, const height& r) {
                os << r.value_;
                return os;
            }
        private:
            millimeter value_;
    };
} // namespace

#endif // DIMENSION_HEIGHT_HPP__
