#pragma once

#include <concepts>
#include <iostream>

namespace lab4 {

template <typename T>
concept Scalar = std::is_scalar_v<T>;

template <Scalar T>
struct Point {
  T x, y;

  Point();
  Point(T xVal, T yVal);

  bool operator==(const Point& other) const;

  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }

  friend std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
  }
};

}  // namespace lab4

#include "point.ipp"
