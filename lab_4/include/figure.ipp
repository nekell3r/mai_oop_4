#pragma once

namespace lab4 {

template <Scalar T>
Figure<T>::operator double() const {
  return GetArea();
}

template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
  figure.Print(os);
  return os;
}

template <Scalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) {
  figure.Read(is);
  return is;
}

template <Scalar T>
bool operator==(const Figure<T>& lhs, const Figure<T>& rhs) {
  return lhs.IsEqual(rhs);
}

}  // namespace lab4
