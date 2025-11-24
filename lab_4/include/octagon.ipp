#pragma once

namespace lab4 {

template <Scalar T>
Octagon<T>::Octagon() {
  for (size_t i = 0; i < VERTICES; ++i) {
    vertices_[i] = Point<T>(0, 0);
  }
}

template <Scalar T>
Octagon<T>::Octagon(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4,
                    const Point<T>& p5, const Point<T>& p6, const Point<T>& p7,
                    const Point<T>& p8) {
  vertices_[0] = p1;
  vertices_[1] = p2;
  vertices_[2] = p3;
  vertices_[3] = p4;
  vertices_[4] = p5;
  vertices_[5] = p6;
  vertices_[6] = p7;
  vertices_[7] = p8;
}

template <Scalar T>
Point<T> Octagon<T>::GetCenter() const {
  T cx = 0;
  T cy = 0;
  for (size_t i = 0; i < VERTICES; ++i) {
    cx += vertices_[i].x;
    cy += vertices_[i].y;
  }
  return Point<T>(cx / static_cast<T>(VERTICES), cy / static_cast<T>(VERTICES));
}

template <Scalar T>
double Octagon<T>::GetArea() const {
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
void Octagon<T>::Print(std::ostream& os) const {
  os << "Octagon: ";
  for (size_t i = 0; i < VERTICES; ++i) {
    os << vertices_[i];
    if (i < VERTICES - 1) {
      os << " ";
    }
  }
}

template <Scalar T>
void Octagon<T>::Read(std::istream& is) {
  for (size_t i = 0; i < VERTICES; ++i) {
    is >> vertices_[i];
  }
}

template <Scalar T>
std::unique_ptr<Figure<T>> Octagon<T>::Clone() const {
  return std::make_unique<Octagon<T>>(*this);
}

template <Scalar T>
bool Octagon<T>::IsEqual(const Figure<T>& other) const {
  const auto* o = dynamic_cast<const Octagon<T>*>(&other);
  if (!o) {
    return false;
  }
  return *this == *o;
}

template <Scalar T>
bool Octagon<T>::operator==(const Octagon& other) const {
  for (size_t i = 0; i < VERTICES; ++i) {
    if (!(vertices_[i] == other.vertices_[i])) {
      return false;
    }
  }
  return true;
}

template <Scalar T>
void Octagon<T>::GetVertices(std::ostream& os) const {
  os << "Octagon vertices: ";
  for (size_t i = 0; i < VERTICES; ++i) {
    os << vertices_[i];
    if (i < VERTICES - 1) {
      os << " ";
    }
  }
}

}  // namespace lab4
