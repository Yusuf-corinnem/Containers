#include "../map/s21_map.h"

#include <map>

#include "gtest/gtest.h"

TEST(MapConstructors, Default) {
  s21::map<int, int> our_map;
  std::map<int, int> std_map;
  EXPECT_EQ(our_map.empty(), std_map.empty());
}

TEST(MapConstructors, Initmap) {
  s21::map<int, int> our_map({{1, 1}, {2, 2}, {3, 3}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}});
  s21::map<int, int>::MapIterator our_it;
  our_it = our_map.begin();
  std::map<int, int>::iterator std_it = std_map.begin();
  for (; std_it != std_map.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MapConstructors, Copy) {
  s21::map<int, int> our_map({{1, 1}, {2, 2}, {3, 3}});
  s21::map<int, int> our_map2(our_map);

  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}});
  std::map<int, int> std_map2(std_map);

  s21::map<int, int>::MapIterator our_it;
  our_it = our_map2.begin();
  std::map<int, int>::iterator std_it = std_map2.begin();
  for (; std_it != std_map2.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MapConstructors, Move) {
  s21::map<int, int> our_map({{1, 1}, {2, 2}, {3, 3}});
  s21::map<int, int> our_map2(std::move(our_map));

  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}});
  std::map<int, int> std_map2(std::move(std_map));

  s21::map<int, int>::MapIterator our_it;
  our_it = our_map2.begin();
  std::map<int, int>::iterator std_it = std_map2.begin();
  for (; std_it != std_map2.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
  EXPECT_EQ(our_map.empty(), std_map.empty());
}

TEST(MapOperator, Move) {
  s21::map<int, int> our_map({{1, 1}, {2, 2}, {3, 3}});
  s21::map<int, int> our_map2 = std::move(our_map);

  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}});
  std::map<int, int> std_map2 = std::move(std_map);

  s21::map<int, int>::MapIterator our_it;
  our_it = our_map2.begin();
  std::map<int, int>::iterator std_it = std_map2.begin();
  for (; std_it != std_map2.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
  EXPECT_EQ(our_map.empty(), std_map.empty());
}

TEST(MapFunctions, At) {
  s21::map<int, int> our_map({{1, 1}, {2, 2}, {3, 3}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}});
  EXPECT_EQ(our_map.at(1), std_map.at(1));
  EXPECT_ANY_THROW(our_map.at(5));
  EXPECT_ANY_THROW(std_map.at(5));
}

TEST(MapOperator, Pos) {
  s21::map<int, char> our_map(
      {{1, 's'}, {2, 't'}, {3, 'o'}, {4, 'c'}, {5, 'h'}});
  std::map<int, char> std_map(
      {{1, 's'}, {2, 't'}, {3, 'o'}, {4, 'c'}, {5, 'h'}});
  EXPECT_EQ(our_map[1], std_map[1]);
  EXPECT_EQ(our_map[5], std_map[5]);
}

TEST(MapFunctions, Size) {
  s21::map<int, char> our_map(
      {{1, 's'}, {2, 't'}, {3, 'o'}, {4, 'c'}, {5, 'h'}});
  std::map<int, char> std_map(
      {{1, 's'}, {2, 't'}, {3, 'o'}, {4, 'c'}, {5, 'h'}});
  EXPECT_EQ(our_map.size(), std_map.size());
}

TEST(MapFunctions, KingSize) {
  s21::map<int, char> our_map(
      {{1, 's'}, {2, 't'}, {3, 'o'}, {4, 'c'}, {5, 'h'}});
  std::map<int, char> std_map(
      {{1, 's'}, {2, 't'}, {3, 'o'}, {4, 'c'}, {5, 'h'}});
  EXPECT_EQ(our_map.max_size(), std_map.max_size());
}

TEST(MapFunctions, Clear) {
  s21::map<int, char> our_map(
      {{1, 's'}, {2, 't'}, {3, 'o'}, {4, 'c'}, {5, 'h'}});
  std::map<int, char> std_map(
      {{1, 's'}, {2, 't'}, {3, 'o'}, {4, 'c'}, {5, 'h'}});
  our_map.clear();
  std_map.clear();
  EXPECT_EQ(our_map.empty(), std_map.empty());
}

TEST(MapFunctions, Insert) {
  s21::map<int, char> our_map(
      {{1, 's'}, {2, 't'}, {3, 'o'}, {4, 'c'}, {5, 'h'}});
  std::map<int, char> std_map(
      {{1, 's'}, {2, 't'}, {3, 'o'}, {4, 'c'}, {5, 'h'}});

  our_map.insert(6, 'k');
  std_map.insert({6, 'k'});
  EXPECT_EQ(our_map[6], std_map[6]);

  our_map.insert(3, 'k');
  std_map.insert({3, 'k'});
  EXPECT_EQ(our_map[3], std_map[3]);
}

TEST(MapFunctions, Erase) {
  s21::map<int, int> our_map({{1, 142}, {2, 2543}, {3, 3214}});
  std::map<int, int> std_map({{1, 142}, {2, 2543}, {3, 3214}});
  s21::map<int, int>::MapIterator our_it;
  our_map.erase(our_map.begin());
  our_it = our_map.begin();
  std_map.erase(std_map.begin());
  EXPECT_EQ(*our_it, *std_map.begin());
}

TEST(MapFunctions, Swap) {
  s21::map<int, int> our_map({{1, 1}, {2, 2}, {3, 3}});
  s21::map<int, int> our_map2;
  our_map2.swap(our_map);

  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}});
  std::map<int, int> std_map2;
  std_map2.swap(std_map2);

  s21::map<int, int>::MapIterator our_it;
  our_it = our_map2.begin();
  std::map<int, int>::iterator std_it = std_map2.begin();
  for (; std_it != std_map2.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MapFunctions, Merge) {
  s21::map<int, int> our_map({{1, 1}, {2, 2}, {3, 3}});
  s21::map<int, int> our_map2({{4, 4}, {5, 5}});
  our_map.merge(our_map2);

  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}});
  std::map<int, int> std_map2({{4, 4}, {5, 5}});
  std_map.merge(std_map2);

  s21::map<int, int>::MapIterator our_it;
  our_it = our_map2.begin();
  std::map<int, int>::iterator std_it = std_map2.begin();
  for (; std_it != std_map2.end(); ++std_it, ++our_it) {
    EXPECT_EQ(*(our_it), *(std_it));
  }
}

TEST(MapFunctions, Contains) {
  s21::map<int, int> our_map({{1, 1}, {2, 2}, {3, 3}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}});
  EXPECT_EQ(our_map.contains(2), true);
  EXPECT_EQ(our_map.contains(4), false);
}
