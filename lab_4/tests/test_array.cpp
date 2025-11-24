#include "array.hpp"

#include <sstream>

#include <gtest/gtest.h>

#include "octagon.hpp"
#include "square.hpp"
#include "triangle.hpp"

using lab4::Array;
using lab4::Triangle;
using lab4::Square;
using lab4::Octagon;
using lab4::Point;

TEST(ArrayTest, DefaultConstructor) {
  Array<int> array;
  EXPECT_EQ(array.GetSize(), 0);
}

TEST(ArrayTest, AddFigure) {
  Array<int> array;

  auto triangle =
      std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3));
  array.Add(std::move(triangle));

  EXPECT_EQ(array.GetSize(), 1);
}

TEST(ArrayTest, AddMultipleFigures) {
  Array<int> array;

  array.Add(std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3)));
  array.Add(std::make_unique<Square<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(4, 4),
                                          Point<int>(0, 4)));
  array.Add(std::make_unique<Octagon<int>>(Point<int>(1, 0), Point<int>(3, 0), Point<int>(4, 1),
                                           Point<int>(4, 3), Point<int>(3, 4), Point<int>(1, 4),
                                           Point<int>(0, 3), Point<int>(0, 1)));

  EXPECT_EQ(array.GetSize(), 3);
}

TEST(ArrayTest, AccessByIndex) {
  Array<int> array;

  auto triangle =
      std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3));
  double area = triangle->GetArea();
  array.Add(std::move(triangle));

  EXPECT_DOUBLE_EQ(array[0]->GetArea(), area);
}

TEST(ArrayTest, AccessByIndexOutOfRange) {
  Array<int> array;
  EXPECT_THROW(array[0], std::out_of_range);
}

TEST(ArrayTest, RemoveFigure) {
  Array<int> array;

  array.Add(std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3)));
  array.Add(std::make_unique<Square<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(4, 4),
                                          Point<int>(0, 4)));

  EXPECT_EQ(array.GetSize(), 2);

  array.Remove(0);
  EXPECT_EQ(array.GetSize(), 1);
}

TEST(ArrayTest, RemoveOutOfRange) {
  Array<int> array;
  array.Add(std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3)));

  EXPECT_THROW(array.Remove(5), std::out_of_range);
}

TEST(ArrayTest, GetTotalArea) {
  Array<int> array;

  array.Add(std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3)));
  array.Add(std::make_unique<Square<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(4, 4),
                                          Point<int>(0, 4)));

  EXPECT_DOUBLE_EQ(array.GetTotalArea(), 22.0);  // 6 + 16
}

TEST(ArrayTest, MoveConstructor) {
  Array<int> array1;
  array1.Add(std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3)));
  array1.Add(std::make_unique<Square<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(4, 4),
                                           Point<int>(0, 4)));

  size_t size1 = array1.GetSize();
  double area1 = array1.GetTotalArea();

  Array<int> array2(std::move(array1));

  EXPECT_EQ(array2.GetSize(), size1);
  EXPECT_DOUBLE_EQ(array2.GetTotalArea(), area1);
  EXPECT_EQ(array1.GetSize(), 0);
}

TEST(ArrayTest, MoveAssignment) {
  Array<int> array1;
  array1.Add(std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3)));
  array1.Add(std::make_unique<Square<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(4, 4),
                                           Point<int>(0, 4)));

  size_t size1 = array1.GetSize();
  double area1 = array1.GetTotalArea();

  Array<int> array2;
  array2 = std::move(array1);

  EXPECT_EQ(array2.GetSize(), size1);
  EXPECT_DOUBLE_EQ(array2.GetTotalArea(), area1);
  EXPECT_EQ(array1.GetSize(), 0);
}

TEST(ArrayTest, PrintAll) {
  Array<int> array;

  array.Add(std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3)));
  array.Add(std::make_unique<Square<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(4, 4),
                                          Point<int>(0, 4)));

  std::ostringstream oss;
  array.PrintAll(oss);
  EXPECT_FALSE(oss.str().empty());
}

TEST(ArrayTest, PrintCenters) {
  Array<int> array;

  array.Add(std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3)));
  array.Add(std::make_unique<Square<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(4, 4),
                                          Point<int>(0, 4)));

  std::ostringstream oss;
  array.PrintCenters(oss);
  EXPECT_FALSE(oss.str().empty());
}

TEST(ArrayTest, PrintVertices) {
  Array<int> array;

  array.Add(std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3)));
  array.Add(std::make_unique<Square<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(4, 4),
                                          Point<int>(0, 4)));

  std::ostringstream oss;
  array.PrintVertices(oss);
  EXPECT_FALSE(oss.str().empty());
}

TEST(ArrayTest, ArrayWithSquare) {
  Array<double> array;

  array.Add(std::make_unique<Square<double>>(Point<double>(0, 0), Point<double>(2, 0),
                                             Point<double>(2, 2), Point<double>(0, 2)));
  array.Add(std::make_unique<Square<double>>(Point<double>(3, 3), Point<double>(5, 3),
                                             Point<double>(5, 5), Point<double>(3, 5)));

  EXPECT_EQ(array.GetSize(), 2);
  EXPECT_DOUBLE_EQ(array.GetTotalArea(), 8.0);  // 4 + 4
}

TEST(ArrayTest, ResizeCapacity) {
  Array<int> array;

  // Добавляем много фигур, чтобы проверить, что массив автоматически расширяется
  for (int i = 0; i < 10; ++i) {
    array.Add(
        std::make_unique<Triangle<int>>(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3)));
  }

  EXPECT_EQ(array.GetSize(), 10);
  EXPECT_DOUBLE_EQ(array.GetTotalArea(), 60.0);  // 6 * 10
}
