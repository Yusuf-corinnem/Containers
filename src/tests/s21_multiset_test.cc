#include "../multiset/s21_multiset.h"

#include <set>

#include "gtest/gtest.h"

TEST(MultisetConstructors, Default) {
  s21::multiset<int> our_set;
  std::multiset<int> std_set;
  EXPECT_EQ(our_set.empty(), std_set.empty());
}

TEST(MultisetConstructors, Init) {
  s21::multiset<int> our_multiset({1, 2, 3, 3, 4, 4});
  std::multiset<int> std_multiset({1, 2, 3, 3, 4, 4});
  s21::multiset<int>::iterator our_it = our_multiset.begin();
  std::multiset<int>::iterator std_it = std_multiset.begin();
  for (; std_it != std_multiset.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  };
}

TEST(MultisetConstructors, Copy) {
  s21::multiset<int> our_multiset({1, 2, 3, 3, 4, 4});
  std::multiset<int> std_multiset({1, 2, 3, 3, 4, 4});
  s21::multiset<int>::iterator our_it = our_multiset.begin();
  std::multiset<int>::iterator std_it = std_multiset.begin();
  for (; std_it != std_multiset.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MultisetConstructors, Move) {
  s21::multiset<int> our_multiset({1, 2, 3, 3, 4, 4});
  s21::multiset<int> our_multiset1(std::move(our_multiset));

  std::multiset<int> std_multiset({1, 2, 3, 3, 4, 4});
  std::multiset<int> std_multiset1(std::move(std_multiset));

  s21::multiset<int>::iterator our_it = our_multiset1.begin();
  std::multiset<int>::iterator std_it = std_multiset1.begin();
  for (; std_it != std_multiset1.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MultisetOperator, Move) {
  s21::multiset<int> our_multiset({1, 2, 3, 3, 4, 4});
  s21::multiset<int> our_multiset1 = std::move(our_multiset);

  std::multiset<int> std_multiset({1, 2, 3, 3, 4, 4});
  std::multiset<int> std_multiset1 = std::move(std_multiset);

  s21::multiset<int>::iterator our_it = our_multiset1.begin();
  std::multiset<int>::iterator std_it = std_multiset1.begin();
  for (; std_it != std_multiset1.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MultisetFunctions, Empty) {  // SmileFace
  s21::multiset<int> our_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(our_multiset.empty(), std_multiset.empty());
}

TEST(MultisetFunctions, UnEmpty) {  // UnSmileFace
  s21::multiset<int> our_multiset({2, 3});
  std::multiset<int> std_multiset({2, 3});
  EXPECT_EQ(our_multiset.empty(), std_multiset.empty());
}

TEST(MultisetFunctions, Count) {
  s21::multiset<int> our_multiset({1, 2, 2, 2, 2, 3});
  std::multiset<int> std_multiset({1, 2, 2, 2, 2, 3});
  EXPECT_EQ(our_multiset.count(2), std_multiset.count(2));
  EXPECT_EQ(our_multiset.count(4), std_multiset.count(4));
}

TEST(MultisetFunctions, EqualRange) {
  s21::multiset<int> our_multiset({1, 2, 2, 2, 2, 3});
  std::multiset<int> std_multiset({1, 2, 2, 2, 2, 3});
  auto range = our_multiset.equal_range(2);
  auto range2 = std_multiset.equal_range(2);
  auto itr = range.first;
  for (auto itr2 = range2.first; itr2 != range2.second; ++itr2, ++itr) {
    EXPECT_EQ(*itr, *itr2);
  }
}

TEST(MultisetFunctions, LowerBound) {
  s21::multiset<int> our_multiset({1, 2, 2, 2, 2, 3});
  std::multiset<int> std_multiset({1, 2, 2, 2, 2, 3});
  EXPECT_EQ(*our_multiset.lower_bound(2), *std_multiset.lower_bound(2));
}

TEST(MultisetFunctions, UpperBound) {
  s21::multiset<int> our_multiset({1, 2, 2, 2, 2, 3});
  std::multiset<int> std_multiset({1, 2, 2, 2, 2, 3});
  EXPECT_EQ(*our_multiset.upper_bound(2), *std_multiset.upper_bound(2));
}