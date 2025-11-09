#pragma once

#include <memory>
#include <stdexcept>

#include "figure.hpp"

namespace lab4 {

template <Scalar T>
class Array {
 private:
  std::shared_ptr<std::shared_ptr<Figure<T>>[]> data_;
  size_t size_;
  size_t capacity_;

  void Resize();

 public:
  Array();
  ~Array();

  Array(const Array&) = delete;
  Array& operator=(const Array&) = delete;

  Array(Array&& other) noexcept;
  Array& operator=(Array&& other) noexcept;

  void Add(std::unique_ptr<Figure<T>> figure);
  void Remove(size_t index);

  std::shared_ptr<Figure<T>> operator[](size_t index) const;

  size_t GetSize() const;
  double GetTotalArea() const;

  void PrintAll(std::ostream& os) const;
  void PrintCenters(std::ostream& os) const;
  void PrintVertices(std::ostream& os) const;
};

}  // namespace lab4

#include "array.ipp"
