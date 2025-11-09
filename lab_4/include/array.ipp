#pragma once

#include <utility>

namespace lab4 {

template <Scalar T>
void Array<T>::Resize() {
  size_t new_cap = capacity_ == 0 ? 1 : capacity_ * 2;
  auto new_data = std::shared_ptr<Figure<T>*[]>(
      new Figure<T>*[new_cap](),
      std::default_delete<Figure<T>*[]>());

  for (size_t i = 0; i < size_; ++i) {
    new_data[i] = data_[i];
  }

  data_ = std::move(new_data);
  capacity_ = new_cap;
}

template <Scalar T>
Array<T>::Array() : data_(nullptr), size_(0), capacity_(0) {}

template <Scalar T>
Array<T>::~Array() {
  for (size_t i = 0; i < size_; ++i) {
    delete data_[i];
  }
}

template <Scalar T>
Array<T>::Array(Array&& other) noexcept
    : data_(std::move(other.data_)), size_(other.size_), capacity_(other.capacity_) {
  other.size_ = 0;
  other.capacity_ = 0;
}

template <Scalar T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
  if (this != &other) {
    for (size_t i = 0; i < size_; ++i) {
      delete data_[i];
    }

    data_ = std::move(other.data_);
    size_ = other.size_;
    capacity_ = other.capacity_;

    other.size_ = 0;
    other.capacity_ = 0;
  }
  return *this;
}

template <Scalar T>
void Array<T>::Add(std::unique_ptr<Figure<T>> figure) {
  if (size_ == capacity_) {
    Resize();
  }
  data_[size_++] = figure.release();
}

template <Scalar T>
void Array<T>::Remove(size_t index) {
  if (index >= size_) {
    throw std::out_of_range("Index out of range");
  }

  delete data_[index];

  for (size_t i = index; i < size_ - 1; ++i) {
    data_[i] = data_[i + 1];
  }

  data_[size_ - 1] = nullptr;
  --size_;
}

template <Scalar T>
std::shared_ptr<Figure<T>> Array<T>::operator[](size_t index) const {
  if (index >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return std::shared_ptr<Figure<T>>(data_, data_[index]);
}

template <Scalar T>
size_t Array<T>::GetSize() const {
  return size_;
}

template <Scalar T>
double Array<T>::GetTotalArea() const {
  double total = 0.0;
  for (size_t i = 0; i < size_; ++i) {
    if (data_[i]) {
      total += data_[i]->GetArea();
    }
  }
  return total;
}

template <Scalar T>
void Array<T>::PrintAll(std::ostream& os) const {
  for (size_t i = 0; i < size_; ++i) {
    if (data_[i]) {
      os << "Figure " << i << ": ";
      data_[i]->Print(os);
      os << "\n";
    }
  }
}

template <Scalar T>
void Array<T>::PrintCenters(std::ostream& os) const {
  for (size_t i = 0; i < size_; ++i) {
    if (data_[i]) {
      os << "Figure " << i << " center: " << data_[i]->GetCenter() << "\n";
    }
  }
}

template <Scalar T>
void Array<T>::PrintVertices(std::ostream& os) const {
  for (size_t i = 0; i < size_; ++i) {
    if (data_[i]) {
      os << "Figure " << i << " - ";
      data_[i]->GetVertices(os);
      os << "\n";
    }
  }
}

}  // namespace lab4
