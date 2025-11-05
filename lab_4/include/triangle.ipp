#pragma once

namespace lab4 {

template <Scalar T>
Triangle<T>::Triangle() {
  vertices_[0] = Point<T>(0, 0);
  vertices_[1] = Point<T>(1, 0);
  vertices_[2] = Point<T>(0, 1);
}

template <Scalar T>
Triangle<T>::Triangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) {
  vertices_[0] = p1;
  vertices_[1] = p2;
  vertices_[2] = p3;
}

template <Scalar T>
Point<T> Triangle<T>::GetCenter() const {
  T cx = (vertices_[0].x + vertices_[1].x + vertices_[2].x) / static_cast<T>(3);
  T cy = (vertices_[0].y + vertices_[1].y + vertices_[2].y) / static_cast<T>(3);
  return Point<T>(cx, cy);
}

template <Scalar T>
double Triangle<T>::GetArea() const {
  double x1 = static_cast<double>(vertices_[0].x);
  double y1 = static_cast<double>(vertices_[0].y);
  double x2 = static_cast<double>(vertices_[1].x);
  double y2 = static_cast<double>(vertices_[1].y);
  double x3 = static_cast<double>(vertices_[2].x);
  double y3 = static_cast<double>(vertices_[2].y);

  return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

template <Scalar T>
void Triangle<T>::Print(std::ostream& os) const {
  os << "Triangle: ";
  for (size_t i = 0; i < VERTICES; ++i) {
    os << vertices_[i];
    if (i < VERTICES - 1) {
      os << " ";
    }
  }
}

template <Scalar T>
void Triangle<T>::Read(std::istream& is) {
  for (size_t i = 0; i < VERTICES; ++i) {
    is >> vertices_[i];
  }
}

template <Scalar T>
std::unique_ptr<Figure<T>> Triangle<T>::Clone() const {
  return std::make_unique<Triangle<T>>(*this);
}

template <Scalar T>
bool Triangle<T>::IsEqual(const Figure<T>& other) const {
  const auto* t = dynamic_cast<const Triangle<T>*>(&other);
  if (!t) {
    return false;
  }
  return *this == *t;
}

template <Scalar T>
bool Triangle<T>::operator==(const Triangle& other) const {
  for (size_t i = 0; i < VERTICES; ++i) {
    if (!(vertices_[i] == other.vertices_[i])) {
      return false;
    }
  }
  return true;
}

template <Scalar T>
void Triangle<T>::GetVertices(std::ostream& os) const {
  os << "Triangle vertices: ";
  for (size_t i = 0; i < VERTICES; ++i) {
    os << vertices_[i];
    if (i < VERTICES - 1) {
      os << " ";
    }
  }
}

}  // namespace lab4
