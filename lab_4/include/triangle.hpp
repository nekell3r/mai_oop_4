#pragma once

#include <array>
#include <cmath>
#include <memory>

#include "figure.hpp"

namespace lab4 {

template <Scalar T>
class Triangle : public Figure<T> {
 private:
  static constexpr size_t VERTICES = 3;
  std::array<Point<T>, VERTICES> vertices_;

 public:
  Triangle();
  Triangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3);
  Triangle(const Triangle& other) = default;
  Triangle(Triangle&& other) noexcept = default;

  Triangle& operator=(const Triangle& other) = default;
  Triangle& operator=(Triangle&& other) noexcept = default;

  ~Triangle() override = default;

  Point<T> GetCenter() const override;
  double GetArea() const override;
  void Print(std::ostream& os) const override;
  void Read(std::istream& is) override;
  std::unique_ptr<Figure<T>> Clone() const override;
  bool IsEqual(const Figure<T>& other) const override;
  void GetVertices(std::ostream& os) const override;

  bool operator==(const Triangle& other) const;
};

}  // namespace lab4

#include "triangle.ipp"
