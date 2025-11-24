#pragma once

#include <iostream>
#include <memory>

#include "point.hpp"

namespace lab4 {

template <Scalar T>
class Figure {
 public:
  virtual ~Figure() = default;

  virtual Point<T> GetCenter() const = 0;
  virtual double GetArea() const = 0;

  explicit operator double() const;

  virtual void Print(std::ostream& os) const = 0;
  virtual void Read(std::istream& is) = 0;

  virtual std::unique_ptr<Figure<T>> Clone() const = 0;
  virtual bool IsEqual(const Figure<T>& other) const = 0;
  virtual void GetVertices(std::ostream& os) const = 0;
};

template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure);

template <Scalar T>
std::istream& operator>>(std::istream& is, Figure<T>& figure);

template <Scalar T>
bool operator==(const Figure<T>& lhs, const Figure<T>& rhs);

}  // namespace lab4

#include "figure.ipp"
