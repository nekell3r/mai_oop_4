#include <iostream>
#include <memory>

#include "array.hpp"
#include "octagon.hpp"
#include "square.hpp"
#include "triangle.hpp"

int main() {
  std::cout << "=== Figures test ===\n\n";

  lab4::Array<int> arr;

  auto t = std::make_unique<lab4::Triangle<int>>(
      lab4::Point<int>(0, 0), lab4::Point<int>(4, 0), lab4::Point<int>(2, 3));
  std::cout << "Triangle: " << *t << "\n";
  std::cout << "Center: " << t->GetCenter() << "\n";
  std::cout << "Area: " << t->GetArea() << "\n\n";
  arr.Add(std::move(t));

  auto s = std::make_unique<lab4::Square<int>>(
      lab4::Point<int>(0, 0), lab4::Point<int>(4, 0),
      lab4::Point<int>(4, 4), lab4::Point<int>(0, 4));
  std::cout << "Square: " << *s << "\n";
  std::cout << "Center: " << s->GetCenter() << "\n";
  std::cout << "Area: " << s->GetArea() << "\n\n";
  arr.Add(std::move(s));

  auto o = std::make_unique<lab4::Octagon<int>>(
      lab4::Point<int>(3, 0), lab4::Point<int>(6, 0), lab4::Point<int>(8, 2),
      lab4::Point<int>(8, 5), lab4::Point<int>(6, 7), lab4::Point<int>(3, 7),
      lab4::Point<int>(1, 5), lab4::Point<int>(1, 2));
  std::cout << "Octagon: " << *o << "\n";
  std::cout << "Center: " << o->GetCenter() << "\n";
  std::cout << "Area: " << o->GetArea() << "\n\n";
  arr.Add(std::move(o));

  std::cout << "All figures:\n";
  arr.PrintAll(std::cout);

  std::cout << "\nCenters:\n";
  arr.PrintCenters(std::cout);

  std::cout << "\nTotal area: " << arr.GetTotalArea() << "\n\n";

  std::cout << "Remove square (index 1):\n";
  arr.Remove(1);
  arr.PrintAll(std::cout);
  std::cout << "New total: " << arr.GetTotalArea() << "\n\n";

  lab4::Array<double> arr2;
  auto t2 = std::make_unique<lab4::Triangle<double>>(
      lab4::Point<double>(0, 0), lab4::Point<double>(3.5, 0), 
      lab4::Point<double>(1.75, 3));
  std::cout << "Double triangle: " << *t2 << "\n";
  std::cout << "Area: " << t2->GetArea() << "\n";
  arr2.Add(std::move(t2));

  auto s2 = std::make_unique<lab4::Square<double>>(
      lab4::Point<double>(0, 0), lab4::Point<double>(2.5, 0),
      lab4::Point<double>(2.5, 2.5), lab4::Point<double>(0, 2.5));
  arr2.Add(std::move(s2));

  std::cout << "Total area (double): " << arr2.GetTotalArea() << "\n\n";

  std::cout << "Done\n";
  return 0;
}
