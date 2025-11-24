#pragma once

#include <array>
#include <cmath>
#include <memory>

#include "figure.hpp"

namespace lab4 {

template <Scalar T>
class Square : public Figure<T> {
 private:
  static constexpr size_t VERTICES = 4;
  std::array<Point<T>, VERTICES> vertices_;

 public:
  Square();
  Square(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4);
  Square(const Square& other) = default;
  Square(Square&& other) noexcept = default;

  Square& operator=(const Square& other) = default;
  Square& operator=(Square&& other) noexcept = default;

  ~Square() override = default;

  Point<T> GetCenter() const override;
  double GetArea() const override;
  void Print(std::ostream& os) const override;
  void Read(std::istream& is) override;
  std::unique_ptr<Figure<T>> Clone() const override;
  bool IsEqual(const Figure<T>& other) const override;
  void GetVertices(std::ostream& os) const override;

  bool operator==(const Square& other) const;
};

}  // namespace lab4

#include "square.ipp"
