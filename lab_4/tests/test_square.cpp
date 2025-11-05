#include "square.hpp"

#include <sstream>

#include <gtest/gtest.h>

using namespace lab4;

TEST(SquareTest, DefaultConstructor) {
  Square<int> square;
  EXPECT_DOUBLE_EQ(square.GetArea(), 1.0);
}

TEST(SquareTest, ParameterizedConstructor) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(4, 4);
  Point<int> p4(0, 4);
  Square<int> square(p1, p2, p3, p4);

  EXPECT_DOUBLE_EQ(square.GetArea(), 16.0);
}

TEST(SquareTest, GetCenter) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(4, 4);
  Point<int> p4(0, 4);
  Square<int> square(p1, p2, p3, p4);

  Point<int> center = square.GetCenter();
  EXPECT_EQ(center.x, 2);
  EXPECT_EQ(center.y, 2);
}

TEST(SquareTest, GetArea) {
  Point<double> p1(0.0, 0.0);
  Point<double> p2(3.0, 0.0);
  Point<double> p3(3.0, 3.0);
  Point<double> p4(0.0, 3.0);
  Square<double> square(p1, p2, p3, p4);

  EXPECT_DOUBLE_EQ(square.GetArea(), 9.0);
}

TEST(SquareTest, CopyConstructor) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(4, 4);
  Point<int> p4(0, 4);
  Square<int> square1(p1, p2, p3, p4);
  Square<int> square2(square1);

  EXPECT_DOUBLE_EQ(square1.GetArea(), square2.GetArea());
  EXPECT_TRUE(square1.IsEqual(square2));
}

TEST(SquareTest, CopyAssignment) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(4, 4);
  Point<int> p4(0, 4);
  Square<int> square1(p1, p2, p3, p4);
  Square<int> square2;
  square2 = square1;

  EXPECT_DOUBLE_EQ(square1.GetArea(), square2.GetArea());
  EXPECT_TRUE(square1.IsEqual(square2));
}

TEST(SquareTest, Clone) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(4, 4);
  Point<int> p4(0, 4);
  Square<int> square(p1, p2, p3, p4);
  auto cloned = square.Clone();

  EXPECT_DOUBLE_EQ(square.GetArea(), cloned->GetArea());
}

TEST(SquareTest, IsEqual) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(4, 4);
  Point<int> p4(0, 4);
  Square<int> square1(p1, p2, p3, p4);
  Square<int> square2(p1, p2, p3, p4);
  Square<int> square3(Point<int>(0, 0), Point<int>(2, 0), Point<int>(2, 2), Point<int>(0, 2));

  EXPECT_TRUE(square1.IsEqual(square2));
  EXPECT_FALSE(square1.IsEqual(square3));
}

TEST(SquareTest, OperatorDouble) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(4, 4);
  Point<int> p4(0, 4);
  Square<int> square(p1, p2, p3, p4);

  double area = static_cast<double>(square);
  EXPECT_DOUBLE_EQ(area, 16.0);
}

TEST(SquareTest, PrintAndRead) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(4, 4);
  Point<int> p4(0, 4);
  Square<int> square1(p1, p2, p3, p4);

  std::ostringstream oss;
  square1.Print(oss);
  EXPECT_FALSE(oss.str().empty());

  std::istringstream iss("0 0 4 0 4 4 0 4");
  Square<int> square2;
  square2.Read(iss);
  EXPECT_TRUE(square1.IsEqual(square2));
}
