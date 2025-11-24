#pragma once

namespace lab4 {

template <Scalar T>
Square<T>::Square() {
  vertices_[0] = Point<T>(0, 0);
  vertices_[1] = Point<T>(1, 0);
  vertices_[2] = Point<T>(1, 1);
  vertices_[3] = Point<T>(0, 1);
}

template <Scalar T>
Square<T>::Square(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) {
  vertices_[0] = p1;
  vertices_[1] = p2;
  vertices_[2] = p3;
  vertices_[3] = p4;
}

template <Scalar T>
Point<T> Square<T>::GetCenter() const {
  T cx = (vertices_[0].x + vertices_[1].x + vertices_[2].x + vertices_[3].x) / static_cast<T>(4);
  T cy = (vertices_[0].y + vertices_[1].y + vertices_[2].y + vertices_[3].y) / static_cast<T>(4);
  return Point<T>(cx, cy);
}

template <Scalar T>
double Square<T>::GetArea() const {
  double area = 0.0;
  for (size_t i = 0; i < VERTICES; ++i) {
    size_t j = (i + 1) % VERTICES;
    double xi = static_cast<double>(vertices_[i].x);
    double yi = static_cast<double>(vertices_[i].y);
    double xj = static_cast<double>(vertices_[j].x);
    double yj = static_cast<double>(vertices_[j].y);
    area += xi * yj;
    area -= xj * yi;
  }
  return std::abs(area) / 2.0;
}

template <Scalar T>
void Square<T>::Print(std::ostream& os) const {
  os << "Square: ";
  for (size_t i = 0; i < VERTICES; ++i) {
    os << vertices_[i];
    if (i < VERTICES - 1) {
      os << " ";
    }
  }
}

template <Scalar T>
void Square<T>::Read(std::istream& is) {
  for (size_t i = 0; i < VERTICES; ++i) {
    is >> vertices_[i];
  }
}

template <Scalar T>
std::unique_ptr<Figure<T>> Square<T>::Clone() const {
  return std::make_unique<Square<T>>(*this);
}

template <Scalar T>
bool Square<T>::IsEqual(const Figure<T>& other) const {
  const auto* s = dynamic_cast<const Square<T>*>(&other);
  if (!s) {
    return false;
  }
  return *this == *s;
}

template <Scalar T>
bool Square<T>::operator==(const Square& other) const {
  for (size_t i = 0; i < VERTICES; ++i) {
    if (!(vertices_[i] == other.vertices_[i])) {
      return false;
    }
  }
  return true;
}

template <Scalar T>
void Square<T>::GetVertices(std::ostream& os) const {
  os << "Square vertices: ";
  for (size_t i = 0; i < VERTICES; ++i) {
    os << vertices_[i];
    if (i < VERTICES - 1) {
      os << " ";
    }
  }
}

}  // namespace lab4
