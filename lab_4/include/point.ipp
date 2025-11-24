#pragma once

namespace lab4 {

template <Scalar T>
Point<T>::Point() : x(0), y(0) {}

template <Scalar T>
Point<T>::Point(T xVal, T yVal) : x(xVal), y(yVal) {}

template <Scalar T>
bool Point<T>::operator==(const Point& other) const {
  if constexpr (std::is_floating_point_v<T>) {
    constexpr T EPS = static_cast<T>(1e-9);
    T dx = x - other.x;
    T dy = y - other.y;
    return (dx * dx + dy * dy) < EPS * EPS;
  } else {
    return x == other.x && y == other.y;
  }
}

}  // namespace lab4
