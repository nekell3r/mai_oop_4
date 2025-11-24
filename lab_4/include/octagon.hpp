#pragma once

#include <array>
#include <cmath>
#include <memory>

#include "figure.hpp"

namespace lab4 {

template <Scalar T>
class Octagon : public Figure<T> {
 private:
  static constexpr size_t VERTICES = 8;
  std::array<Point<T>, VERTICES> vertices_;

 public:
  Octagon();
  Octagon(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4,
          const Point<T>& p5, const Point<T>& p6, const Point<T>& p7, const Point<T>& p8);
  Octagon(const Octagon& other) = default;
  Octagon(Octagon&& other) noexcept = default;

  Octagon& operator=(const Octagon& other) = default;
  Octagon& operator=(Octagon&& other) noexcept = default;

  ~Octagon() override = default;

  Point<T> GetCenter() const override;
  double GetArea() const override;
  void Print(std::ostream& os) const override;
  void Read(std::istream& is) override;
  std::unique_ptr<Figure<T>> Clone() const override;
  bool IsEqual(const Figure<T>& other) const override;
  void GetVertices(std::ostream& os) const override;

  bool operator==(const Octagon& other) const;
};

}  // namespace lab4

#include "octagon.ipp"
