#include "triangle.hpp"

#include <sstream>

#include <gtest/gtest.h>

using lab4::Triangle;
using lab4::Point;

TEST(TriangleTest, DefaultConstructor) {
  Triangle<int> triangle;
  EXPECT_DOUBLE_EQ(triangle.GetArea(), 0.5);
}

TEST(TriangleTest, ParameterizedConstructor) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(2, 3);
  Triangle<int> triangle(p1, p2, p3);

  EXPECT_DOUBLE_EQ(triangle.GetArea(), 6.0);
}

TEST(TriangleTest, GetCenter) {
  Point<int> p1(0, 0);
  Point<int> p2(6, 0);
  Point<int> p3(3, 6);
  Triangle<int> triangle(p1, p2, p3);

  Point<int> center = triangle.GetCenter();
  EXPECT_EQ(center.x, 3);
  EXPECT_EQ(center.y, 2);
}

TEST(TriangleTest, GetArea) {
  Point<double> p1(0.0, 0.0);
  Point<double> p2(4.0, 0.0);
  Point<double> p3(2.0, 3.0);
  Triangle<double> triangle(p1, p2, p3);

  EXPECT_DOUBLE_EQ(triangle.GetArea(), 6.0);
}

TEST(TriangleTest, CopyConstructor) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(2, 3);
  Triangle<int> triangle1(p1, p2, p3);
  Triangle<int> triangle2(triangle1);

  EXPECT_DOUBLE_EQ(triangle1.GetArea(), triangle2.GetArea());
  EXPECT_TRUE(triangle1.IsEqual(triangle2));
}

TEST(TriangleTest, CopyAssignment) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(2, 3);
  Triangle<int> triangle1(p1, p2, p3);
  Triangle<int> triangle2;
  triangle2 = triangle1;

  EXPECT_DOUBLE_EQ(triangle1.GetArea(), triangle2.GetArea());
  EXPECT_TRUE(triangle1.IsEqual(triangle2));
}

TEST(TriangleTest, MoveConstructor) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(2, 3);
  Triangle<int> triangle1(p1, p2, p3);
  double area = triangle1.GetArea();
  Triangle<int> triangle2(std::move(triangle1));

  EXPECT_DOUBLE_EQ(triangle2.GetArea(), area);
}

TEST(TriangleTest, Clone) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(2, 3);
  Triangle<int> triangle(p1, p2, p3);
  auto cloned = triangle.Clone();

  EXPECT_DOUBLE_EQ(triangle.GetArea(), cloned->GetArea());
}

TEST(TriangleTest, IsEqual) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(2, 3);
  Triangle<int> triangle1(p1, p2, p3);
  Triangle<int> triangle2(p1, p2, p3);
  Triangle<int> triangle3(Point<int>(0, 0), Point<int>(3, 0), Point<int>(1, 2));

  EXPECT_TRUE(triangle1.IsEqual(triangle2));
  EXPECT_FALSE(triangle1.IsEqual(triangle3));
}

TEST(TriangleTest, OperatorDouble) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(2, 3);
  Triangle<int> triangle(p1, p2, p3);

  double area = static_cast<double>(triangle);
  EXPECT_DOUBLE_EQ(area, 6.0);
}

TEST(TriangleTest, PrintAndRead) {
  Point<int> p1(0, 0);
  Point<int> p2(4, 0);
  Point<int> p3(2, 3);
  Triangle<int> triangle1(p1, p2, p3);

  std::ostringstream oss;
  triangle1.Print(oss);
  EXPECT_FALSE(oss.str().empty());

  std::istringstream iss("0 0 4 0 2 3");
  Triangle<int> triangle2;
  triangle2.Read(iss);
  EXPECT_TRUE(triangle1.IsEqual(triangle2));
}
