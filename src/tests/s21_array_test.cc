#include <array>

#include "gtest/gtest.h"
#include "tests.h"

TEST(ArrayConstructors, Default) {
  s21::array<int, 0> our_array;
  std::array<int, 0> std_array;
  EXPECT_EQ(our_array.empty(), std_array.empty());
}

TEST(ArrayConstructors, InitList) {
  s21::array<int, 3> our_array({1, 2, 3});
  std::array<int, 3> std_array({1, 2, 3});
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(our_array[i], std_array[i]);
  }
}

TEST(ArrayConstructors, Copy) {
  s21::array<int, 3> our_array({3, 4, 5});
  s21::array<int, 3> our_array1(our_array);
  std::array<int, 3> std_array({3, 4, 5});
  std::array<int, 3> std_array1(std_array);
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(our_array1[i], std_array1[i]);
  }
}

TEST(ArrayConstructors, Move) {
  s21::array<int, 3> our_array({3, 4, 5});
  s21::array<int, 3> our_array1(std::move(our_array));
  std::array<int, 3> std_array({3, 4, 5});
  std::array<int, 3> std_array1(std::move(std_array));
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(our_array1[i], std_array1[i]);
  }
}

TEST(ArrayOperator, Move) {
  s21::array<int, 2> our_array({1, 2});
  std::array<int, 2> std_array({1, 2});
  s21::array<int, 2> our_array1 = std::move(our_array);
  std::array<int, 2> std_array1 = std::move(std_array);
  for (int i = 0; i < 2; i++) {
    EXPECT_EQ(our_array1[i], std_array1[i]);
  }
}

TEST(ArrayFunctions, at) {
  s21::array<int, 2> our_array({1, 2});
  std::array<int, 2> std_array({1, 2});
  EXPECT_EQ(our_array.at(0), std_array.at(0));
  EXPECT_ANY_THROW(our_array.at(1000));
}

TEST(ArrayFunctions, front) {
  s21::array<int, 5> our_array({1, 2, 123, 12, 22222222});
  std::array<int, 5> std_array({1, 2, 123, 12, 22222222});
  EXPECT_EQ(our_array.front(), std_array.front());
}

TEST(ArrayFunctions, back) {
  s21::array<int, 5> our_array({1, 2, 123, 12, 22222222});
  std::array<int, 5> std_array({1, 2, 123, 12, 22222222});
  EXPECT_EQ(our_array.back(), std_array.back());
}

TEST(ArrayFunctions, empty) {
  s21::array<int, 5> our_array({1, 2, 123, 12, 22222222});
  std::array<int, 5> std_array({1, 2, 123, 12, 22222222});
  EXPECT_EQ(our_array.empty(), std_array.empty());
  s21::array<int, 0> our_array1;
  std::array<int, 0> std_array1;
  EXPECT_EQ(our_array1.empty(), std_array1.empty());
}

TEST(ArrayFunctions, size) {
  s21::array<int, 5> our_array({1, 2, 123, 12, 22222222});
  std::array<int, 5> std_array({1, 2, 123, 12, 22222222});
  EXPECT_EQ(our_array.size(), std_array.size());
}

TEST(ArrayFunctions, max_size) {
  s21::array<int, 5> our_array({1, 2, 123, 12, 22222222});
  std::array<int, 5> std_array({1, 2, 123, 12, 22222222});
  EXPECT_EQ(our_array.max_size(), std_array.max_size());
}

TEST(ArrayFunctions, swap) {
  s21::array<int, 5> our_array({1, 2, 123, 12, 22222222});
  std::array<int, 5> std_array({1, 2, 123, 12, 22222222});
  s21::array<int, 5> our_array1;
  std::array<int, 5> std_array1;
  our_array1.swap(our_array);
  std_array1.swap(std_array);
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(our_array1[i], std_array1[i]);
  }
}
TEST(ArrayFunctions, fill) {
  s21::array<char, 5> our_array;
  std::array<char, 5> std_array;
  our_array.fill('Z');
  std_array.fill('Z');
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(our_array[i], std_array[i]);
  }
}

TEST(IteratorFunctions, data) {
  s21::array<int, 5> our_array;
  std::array<int, 5> std_array;
  our_array.fill(3);
  std_array.fill(3);
  EXPECT_EQ(*our_array.data(), *std_array.data());
  EXPECT_EQ(*our_array.begin(), *std_array.begin());
  // EXPECT_EQ(*our_array.end(), *std_array.end());
}
