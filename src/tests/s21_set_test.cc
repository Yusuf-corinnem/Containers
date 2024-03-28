#include <set>

#include "gtest/gtest.h"
#include "tests.h"

TEST(SetConstructors, Default) {
  s21::set<int> our_set;
  std::set<int> std_set;
  EXPECT_EQ(our_set.empty(), std_set.empty());
}

TEST(SetConstructors, Initset) {
  s21::set<int> our_set({1, 2, 3});
  std::set<int> std_set({1, 2, 3});
  s21::set<int>::iterator our_it = our_set.begin();
  std::set<int>::iterator std_it = std_set.begin();
  for (; std_it != std_set.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetConstructors, Copy) {
  s21::set<int> our_set({1, 2, 3});
  std::set<int> std_set({1, 2, 3});
  s21::set<int>::iterator our_it = our_set.begin();
  std::set<int>::iterator std_it = std_set.begin();
  for (; std_it != std_set.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetConstructors, Move) {
  s21::set<int> our_set({1, 2, 3});
  s21::set<int> our_set1(std::move(our_set));

  std::set<int> std_set({1, 2, 3});
  std::set<int> std_set1(std::move(std_set));

  s21::set<int>::iterator our_it = our_set1.begin();
  std::set<int>::iterator std_it = std_set1.begin();
  for (; std_it != std_set1.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetOperator, Move) {
  s21::set<int> our_set({1, 2, 3});
  s21::set<int> our_set1 = std::move(our_set);

  std::set<int> std_set({1, 2, 3});
  std::set<int> std_set1 = std::move(std_set);

  s21::set<int>::iterator our_it = our_set1.begin();
  std::set<int>::iterator std_it = std_set1.begin();
  for (; std_it != std_set1.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetFunctions, Empty) {
  s21::set<int> our_set;
  std::set<int> std_set;
  EXPECT_EQ(our_set.empty(), std_set.empty());
}

TEST(SetFunctions, UnEmpty) {  // SmileFace
  s21::set<int> our_set({2, 3});
  std::set<int> std_set({2, 3});
  EXPECT_EQ(our_set.empty(), std_set.empty());
}

TEST(SetFunctions, Size) {  // SmileFace
  s21::set<int> our_set({2, 3, 3, 5, 723, 436, 1});
  std::set<int> std_set({2, 3, 3, 5, 723, 436, 1});
  EXPECT_EQ(our_set.size(), std_set.size());
}

TEST(SetFunctions, KingSize) {  // SmileFace
  s21::set<float> our_set({2, 3, 3, 5, 723.392042390, 436, 1});
  std::set<float> std_set({2, 3, 3, 5, 723.392042390, 436, 1});
  EXPECT_EQ(our_set.max_size(), std_set.max_size());
}

TEST(SetFunctions, Clear) {  // SmileFace
  s21::set<float> our_set({2, 3, 3, 5, 723.392042390, 436, 1});
  std::set<float> std_set({2, 3, 3, 5, 723.392042390, 436, 1});
  our_set.clear();
  std_set.clear();
  EXPECT_EQ(our_set.empty(), std_set.empty());
}

TEST(SetFunctions, Insert) {  // SmileFace
  s21::set<int> our_set;
  std::set<int> std_set;
  our_set.insert(2);
  s21::set<int>::iterator itr = our_set.begin();
  std_set.insert(2);
  std::set<int>::iterator itr2 = std_set.begin();
  EXPECT_EQ(*itr, *itr2);
}

TEST(SetFunctions, Erase) {  // SmileFace
  s21::set<int> our_set({1, 2, 3});
  std::set<int> std_set({1, 2, 3});
  our_set.erase(our_set.begin());
  s21::set<int>::iterator itr = our_set.begin();
  std_set.erase(std_set.begin());
  std::set<int>::iterator itr2 = std_set.begin();
  EXPECT_EQ(*itr, *itr2);
}

TEST(SetFunctions, Swap) {  // SmileFace
  s21::set<int> our_set({1, 2, 3});
  s21::set<int> our_set2({3, 2, 1});
  our_set.swap(our_set2);

  std::set<int> std_set({1, 2, 3});
  std::set<int> std_set2({3, 2, 1});
  std_set.swap(std_set2);

  s21::set<int>::iterator our_it = our_set.begin();
  std::set<int>::iterator std_it = std_set.begin();
  for (; std_it != std_set.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetFunctions, Merge) {  // SmileFace
  s21::set<int> our_set({1, 2, 3});
  s21::set<int> our_set2({3, 4, 5});
  our_set.merge(our_set2);

  std::set<int> std_set({1, 2, 3});
  std::set<int> std_set2({3, 4, 5});
  std_set.merge(std_set2);

  s21::set<int>::iterator our_it = our_set.begin();
  std::set<int>::iterator std_it = std_set.begin();
  std::set<int>::iterator std_it2 = std_set2.begin();
  for (; std_it != std_set.end(); ++std_it, ++our_it, ++std_it2) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(SetFunctions, Find) {  // SmileFace
  s21::set<int> our_set({1, 2, 3});

  std::set<int> std_set({1, 2, 3});

  s21::set<int>::iterator our_it = our_set.find(2);
  std::set<int>::iterator std_it = std_set.find(2);
  EXPECT_EQ(*(our_it), *(std_it));
}

TEST(SetFunctions, Contains) {  // SmileFace
  s21::set<int> our_set({1, 2, 3});
  EXPECT_EQ(our_set.contains(2), true);
  EXPECT_EQ(our_set.contains(4), false);
}