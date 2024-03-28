#include <list>

#include "gtest/gtest.h"
#include "tests.h"

TEST(ListConstructors, Default) {
  s21::list<int> our_list;
  std::list<int> std_list;
  EXPECT_EQ(our_list.empty(), std_list.empty());
}

TEST(ListConstructors, Size) {
  s21::list<int> our_list(3);
  std::list<int> std_list(3);

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListConstructors, InitList) {
  s21::list<int> our_list({1, 2, 3});
  std::list<int> std_list({1, 2, 3});

  while (!our_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListConstructors, Copy) {
  s21::list<int> our_list({1, 2, 3});
  s21::list<int> our_list1(our_list);
  std::list<int> std_list({1, 2, 3});
  std::list<int> std_list1(std_list);

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListConstructors, Move) {
  s21::list<int> our_list({1, 2, 3});
  s21::list<int> our_list1(std::move(our_list));
  std::list<int> std_list({1, 2, 3});
  std::list<int> std_list1(std::move(std_list));

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListOperator, Move) {
  s21::list<int> our_list({1, 2, 3});
  s21::list<int> our_list1 = std::move(our_list);
  std::list<int> std_list({1, 2, 3});
  std::list<int> std_list1 = std::move(std_list);

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListIterators, Begin) {
  s21::list<int> our_list({'s', 't', 'o', 'k'});
  std::list<int> std_list({'s', 't', 'o', 'k'});
  EXPECT_EQ(*our_list.begin(), *std_list.begin());
}

TEST(ListIterators, End) {
  s21::list<int> our_list({1, 2, 3, 4});
  std::list<int> std_list({1, 2, 3, 4});
  EXPECT_EQ(*our_list.end(), *std_list.end());
}

TEST(ListIterators, InsertBegin) {
  s21::list<int> our_list({1, 2});
  our_list.insert(our_list.begin(), 3);
  std::list<int> std_list({1, 2});
  std_list.insert(std_list.begin(), 3);

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListIterators, Insert) {
  s21::list<int> our_list({1, 2});
  s21::list<int>::iterator itr = our_list.begin();
  itr++;
  our_list.insert(itr, 3);

  std::list<int> std_list({1, 2});
  std::list<int>::iterator itr2 = std_list.begin();
  itr2++;
  std_list.insert(itr2, 3);

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListFunctions, Size) {
  s21::list<char> our_list({'s', 't', 'o', 'k'});
  std::list<char> std_list({'s', 't', 'o', 'k'});
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(ListFunctions, KingSize) {
  s21::list<int> our_list;
  std::list<int> std_list;
  EXPECT_EQ(std_list.max_size(), std_list.max_size());
}

TEST(ListFunctions, Clear) {
  s21::list<char> our_list({'s', 't', 'o', 'k'});
  our_list.clear();
  std::list<char> std_list({'s', 't', 'o', 'k'});
  std_list.clear();
  EXPECT_EQ(our_list.size(), std_list.size());
}

TEST(ListFunctions, EraseBegin) {
  s21::list<int> our_list({1, 2});
  our_list.erase(our_list.begin());

  std::list<int> std_list({1, 2});
  std_list.erase(std_list.begin());

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListFunctions, EraseMiddle) {
  s21::list<int> our_list({1, 2, 3, 4});
  s21::list<int>::iterator itr = our_list.begin();
  itr++;
  our_list.erase(itr);

  std::list<int> std_list({1, 2, 3, 4});
  std::list<int>::iterator itr2 = std_list.begin();
  itr2++;
  std_list.erase(itr2);

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListFunctions, EraseLast) {
  s21::list<int> our_list({1, 2});
  s21::list<int>::iterator itr = our_list.begin();
  itr++;
  our_list.erase(itr);

  std::list<int> std_list({1, 2});
  std::list<int>::iterator itr2 = std_list.begin();
  itr2++;
  std_list.erase(itr2);

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListFunctions, Swap) {
  s21::list<char> our_list({'s', 't', 'o', 'c', 'h'});
  s21::list<char> our1_list;
  our1_list.swap(our_list);

  std::list<char> std_list({'s', 't', 'o', 'c', 'h'});
  std::list<char> std1_list;
  std1_list.swap(std_list);

  while (!std1_list.empty()) {
    EXPECT_EQ(our1_list.front(), std1_list.front());
    our1_list.pop_front();
    std1_list.pop_front();
  }
}

TEST(ListFunctions, Reverse) {
  s21::list<int> our_list({1, 2, 3, 4});
  our_list.reverse();
  std::list<int> std_list({1, 2, 3, 4});
  std_list.reverse();

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListFunctions, Unique) {
  s21::list<int> our_list({4, 1, 1, 3, 3, 4, 4});
  our_list.unique();
  std::list<int> std_list({4, 1, 1, 3, 3, 4, 4});
  std_list.unique();

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListFunctions, Sort) {
  s21::list<int> our_list({6, 5, 4, 3});
  our_list.sort();
  std::list<int> std_list({6, 5, 4, 3});
  std_list.sort();

  while (!std_list.empty()) {
    EXPECT_EQ(our_list.front(), std_list.front());
    our_list.pop_front();
    std_list.pop_front();
  }
}

TEST(ListFunctions, Merge) {
  s21::list<int> our_list({6, 5, 4, 3});
  our_list.sort();
  s21::list<int> our_list1({6, 5, 4, 3});
  our_list1.sort();
  our_list1.merge(our_list);
  std::list<int> std_list({6, 5, 4, 3});
  std_list.sort();
  std::list<int> std_list1({6, 5, 4, 3});
  std_list1.sort();
  std_list1.merge(std_list);

  while (!std_list1.empty()) {
    EXPECT_EQ(our_list1.front(), std_list1.front());
    our_list1.pop_front();
    std_list1.pop_front();
  }
}

TEST(ListFunctions, Spice) {
  s21::list<int> our_list({6, 5, 4, 3});
  s21::list<int> our1_list({4, 3, 4});
  s21::list<int>::const_iterator itr = our_list.begin();
  itr++;
  our1_list.splice(itr, our_list);

  std::list<int> std_list({6, 5, 4, 3});
  std::list<int> std1_list({4, 3, 4});
  std::list<int>::const_iterator itr2 = std_list.begin();
  itr2++;
  std1_list.splice(itr2, std_list);

  while (!std1_list.empty()) {
    EXPECT_EQ(our1_list.front(), std1_list.front());
    our1_list.pop_front();
    std1_list.pop_front();
  }
}
