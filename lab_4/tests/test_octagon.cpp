#include "octagon.hpp"

#include <sstream>

#include <gtest/gtest.h>

using namespace lab4;

TEST(OctagonTest, DefaultConstructor) {
  Octagon<int> octagon;
  EXPECT_DOUBLE_EQ(octagon.GetArea(), 0.0);
}

TEST(OctagonTest, ParameterizedConstructor) {
  Point<int> p1(1, 0);
  Point<int> p2(3, 0);
  Point<int> p3(4, 1);
  Point<int> p4(4, 3);
  Point<int> p5(3, 4);
  Point<int> p6(1, 4);
  Point<int> p7(0, 3);
  Point<int> p8(0, 1);
  Octagon<int> octagon(p1, p2, p3, p4, p5, p6, p7, p8);

  EXPECT_GT(octagon.GetArea(), 0.0);
}

TEST(OctagonTest, GetCenter) {
  Point<int> p1(1, 0);
  Point<int> p2(3, 0);
  Point<int> p3(4, 1);
  Point<int> p4(4, 3);
  Point<int> p5(3, 4);
  Point<int> p6(1, 4);
  Point<int> p7(0, 3);
  Point<int> p8(0, 1);
  Octagon<int> octagon(p1, p2, p3, p4, p5, p6, p7, p8);

  Point<int> center = octagon.GetCenter();
  EXPECT_EQ(center.x, 2);
  EXPECT_EQ(center.y, 2);
}

TEST(OctagonTest, GetArea) {
  Point<int> p1(1, 0);
  Point<int> p2(3, 0);
  Point<int> p3(4, 1);
  Point<int> p4(4, 3);
  Point<int> p5(3, 4);
  Point<int> p6(1, 4);
  Point<int> p7(0, 3);
  Point<int> p8(0, 1);
  Octagon<int> octagon(p1, p2, p3, p4, p5, p6, p7, p8);

  EXPECT_DOUBLE_EQ(octagon.GetArea(), 14.0);
}

TEST(OctagonTest, CopyConstructor) {
  Point<int> p1(1, 0);
  Point<int> p2(3, 0);
  Point<int> p3(4, 1);
  Point<int> p4(4, 3);
  Point<int> p5(3, 4);
  Point<int> p6(1, 4);
  Point<int> p7(0, 3);
  Point<int> p8(0, 1);
  Octagon<int> octagon1(p1, p2, p3, p4, p5, p6, p7, p8);
  Octagon<int> octagon2(octagon1);

  EXPECT_DOUBLE_EQ(octagon1.GetArea(), octagon2.GetArea());
  EXPECT_TRUE(octagon1.IsEqual(octagon2));
}

TEST(OctagonTest, CopyAssignment) {
  Point<int> p1(1, 0);
  Point<int> p2(3, 0);
  Point<int> p3(4, 1);
  Point<int> p4(4, 3);
  Point<int> p5(3, 4);
  Point<int> p6(1, 4);
  Point<int> p7(0, 3);
  Point<int> p8(0, 1);
  Octagon<int> octagon1(p1, p2, p3, p4, p5, p6, p7, p8);
  Octagon<int> octagon2;
  octagon2 = octagon1;

  EXPECT_DOUBLE_EQ(octagon1.GetArea(), octagon2.GetArea());
  EXPECT_TRUE(octagon1.IsEqual(octagon2));
}

TEST(OctagonTest, Clone) {
  Point<int> p1(1, 0);
  Point<int> p2(3, 0);
  Point<int> p3(4, 1);
  Point<int> p4(4, 3);
  Point<int> p5(3, 4);
  Point<int> p6(1, 4);
  Point<int> p7(0, 3);
  Point<int> p8(0, 1);
  Octagon<int> octagon(p1, p2, p3, p4, p5, p6, p7, p8);
  auto cloned = octagon.Clone();

  EXPECT_DOUBLE_EQ(octagon.GetArea(), cloned->GetArea());
}

TEST(OctagonTest, IsEqual) {
  Point<int> p1(1, 0);
  Point<int> p2(3, 0);
  Point<int> p3(4, 1);
  Point<int> p4(4, 3);
  Point<int> p5(3, 4);
  Point<int> p6(1, 4);
  Point<int> p7(0, 3);
  Point<int> p8(0, 1);
  Octagon<int> octagon1(p1, p2, p3, p4, p5, p6, p7, p8);
  Octagon<int> octagon2(p1, p2, p3, p4, p5, p6, p7, p8);

  Point<int> q1(0, 0);
  Point<int> q2(2, 0);
  Point<int> q3(3, 1);
  Point<int> q4(3, 3);
  Point<int> q5(2, 4);
  Point<int> q6(0, 4);
  Point<int> q7(-1, 3);
  Point<int> q8(-1, 1);
  Octagon<int> octagon3(q1, q2, q3, q4, q5, q6, q7, q8);

  EXPECT_TRUE(octagon1.IsEqual(octagon2));
  EXPECT_FALSE(octagon1.IsEqual(octagon3));
}

TEST(OctagonTest, OperatorDouble) {
  Point<int> p1(1, 0);
  Point<int> p2(3, 0);
  Point<int> p3(4, 1);
  Point<int> p4(4, 3);
  Point<int> p5(3, 4);
  Point<int> p6(1, 4);
  Point<int> p7(0, 3);
  Point<int> p8(0, 1);
  Octagon<int> octagon(p1, p2, p3, p4, p5, p6, p7, p8);

  double area = static_cast<double>(octagon);
  EXPECT_DOUBLE_EQ(area, 14.0);
}

TEST(OctagonTest, PrintAndRead) {
  Point<int> p1(1, 0);
  Point<int> p2(3, 0);
  Point<int> p3(4, 1);
  Point<int> p4(4, 3);
  Point<int> p5(3, 4);
  Point<int> p6(1, 4);
  Point<int> p7(0, 3);
  Point<int> p8(0, 1);
  Octagon<int> octagon1(p1, p2, p3, p4, p5, p6, p7, p8);

  std::ostringstream oss;
  octagon1.Print(oss);
  EXPECT_FALSE(oss.str().empty());

  std::istringstream iss("1 0 3 0 4 1 4 3 3 4 1 4 0 3 0 1");
  Octagon<int> octagon2;
  octagon2.Read(iss);
  EXPECT_TRUE(octagon1.IsEqual(octagon2));
}
