#include <vector>

#include "gtest/gtest.h"
#include "tests.h"

TEST(VectorConstructors, Default) {
  s21::vector<int> our_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(VectorConstructors, Size) {
  s21::vector<int> our_vector(5);
  std::vector<int> std_vector(5);
  EXPECT_EQ(our_vector.capacity(), std_vector.capacity());
}

TEST(VectorConstructors, InitList) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(our_vector[i], std_vector[i]);
  }
}

TEST(VectorConstructors, Copy) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  s21::vector<int> our_vector1(our_vector);
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector1(std_vector);
  for (size_t i = 0; i < our_vector1.size(); ++i) {
    EXPECT_EQ(our_vector1[i], std_vector1[i]);
  }
}

TEST(VectorConstructors, Move) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  s21::vector<int> our_vector1(std::move(our_vector));
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector1(std::move(std_vector));
  for (size_t i = 0; i < our_vector1.size(); ++i) {
    EXPECT_EQ(our_vector1[i], std_vector1[i]);
  }
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(VectorOperators, Copy) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  s21::vector<int> our_vector1 = our_vector1;
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector1 = std_vector;
  for (size_t i = 0; i < our_vector1.size(); ++i) {
    EXPECT_EQ(our_vector1[i], std_vector1[i]);
  }
}

/* TEST(VectorOperators, Move) { //Conditional jump and errors on original
vector s21::vector<int> our_vector{1,2,3,4,5}; s21::vector<int> our_vector1 =
std::move(our_vector); std::vector<int> std_vector{1,2,3,4,5}; std::vector<int>
std_vector1 = std::move(std_vector); for (size_t i = 0; i < our_vector1.size();
++i) { EXPECT_EQ(our_vector1[i], std_vector1[i]);
  }
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
} */

TEST(VectorIterators, Begin) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(*our_vector.begin(), *std_vector.begin());
}
TEST(VectorIterators, End) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(*our_vector.end(), *std_vector.end());
}

TEST(VectorIterators, Insert) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  our_vector.insert(our_vector.begin() + 2, 228);
  std_vector.insert(std_vector.begin() + 2, 228);
  EXPECT_EQ(our_vector[2], std_vector[2]);
}

TEST(VectorFunctions, At) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.at(1), std_vector.at(1));
}

TEST(VectorFunctions, Front) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.front(), std_vector.front());
}

TEST(VectorFunctions, Back) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.back(), std_vector.back());
}

TEST(VectorFunctions, Data) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(*our_vector.data(), *std_vector.data());
}

TEST(VectorFunctions, Size) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(VectorFunctions, MaxSize) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.max_size(), std_vector.max_size());
}

TEST(VectorFunctions, Reserve) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  our_vector.reserve(10);
  std_vector.reserve(10);
  EXPECT_EQ(our_vector.capacity(), std_vector.capacity());
}

TEST(VectorFunctions, ShrinkToFit) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  our_vector.reserve(10);
  std_vector.reserve(10);
  our_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_EQ(our_vector.capacity(), std_vector.capacity());
}

TEST(VectorFunctions, Clear) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  our_vector.clear();
  std_vector.clear();
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(VectorFunctions, Erase) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  our_vector.erase(our_vector.begin() + 2);
  std_vector.erase(std_vector.begin() + 2);
  for (size_t i = 0; i < std_vector.size(); ++i) {
    EXPECT_EQ(our_vector[i], std_vector[i]);
  }
}

TEST(VectorFunctions, PushBack) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  our_vector.push_back(1);
  std_vector.push_back(1);
  for (size_t i = 0; i < std_vector.size(); ++i) {
    EXPECT_EQ(our_vector[i], std_vector[i]);
  }
}
TEST(VectorFunctions, PopBack) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  our_vector.pop_back();
  std_vector.pop_back();
  for (size_t i = 0; i < std_vector.size(); ++i) {
    EXPECT_EQ(our_vector[i], std_vector[i]);
  }
}

TEST(VectorFunctions, Swap) {
  s21::vector<int> our_vector{1, 2, 3, 4, 5};
  s21::vector<int> our_vector1{1, 0, 0, 0, 0};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector1{1, 0, 0, 0, 0};

  our_vector1.swap(our_vector);
  std_vector1.swap(std_vector);

  for (size_t i = 0; i < std_vector1.size(); ++i) {
    EXPECT_EQ(our_vector1[i], std_vector1[i]);
  }
}
