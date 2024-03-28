#include <queue>

#include "gtest/gtest.h"
#include "tests.h"

TEST(QueueConstructors, Default) {
  s21::queue<int> our_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(QueueConstructors, InitList) {
  s21::queue<int> our_queue({1, 2, 3});
  std::queue<int> std_queue({1, 2, 3});
  while (!our_queue.empty()) {
    EXPECT_EQ(our_queue.front(), std_queue.front());
    our_queue.pop();
    std_queue.pop();
  }
}

TEST(QueueConstructors, Copy) {
  s21::queue<int> our_queue({3, 4, 5});
  s21::queue<int> our_queue1(our_queue);
  std::queue<int> std_queue({3, 4, 5});
  std::queue<int> std_queue1(std_queue);
  while (!std_queue.empty()) {
    EXPECT_EQ(our_queue.front(), std_queue.front());
    our_queue.pop();
    std_queue.pop();
  }
}

TEST(QueueConstructors, Move) {
  s21::queue<int> our_queue({3, 4, 5});
  s21::queue<int> our_queue1(std::move(our_queue));
  std::queue<int> std_queue({3, 4, 5});
  std::queue<int> std_queue1(std::move(std_queue));
  while (!std_queue1.empty()) {
    EXPECT_EQ(our_queue1.front(), std_queue1.front());
    our_queue1.pop();
    std_queue1.pop();
  }
}

TEST(QueueOperator, Move) {
  s21::queue<int> our_queue({1, 2});
  std::queue<int> std_queue({1, 2});
  s21::queue<int> our_queue1 = std::move(our_queue);
  std::queue<int> std_queue1 = std::move(std_queue);
  while (!std_queue1.empty()) {
    EXPECT_EQ(our_queue1.front(), std_queue1.front());
    our_queue1.pop();
    std_queue1.pop();
  }
}

TEST(QueueFunctions, Push) {
  s21::queue<int> our_queue;
  our_queue.push(1);
  our_queue.push(2);
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(QueueFunctions, Pop) {
  s21::queue<int> our_queue({1, 2});
  our_queue.pop();
  std::queue<int> std_queue({1, 2});
  std_queue.pop();
  EXPECT_EQ(our_queue.front(), std_queue.front());
}

TEST(QueueFunctions, Swap) {
  s21::queue<int> our_queue({1, 2, 3});
  s21::queue<int> our_queue1({4, 5, 6});
  our_queue.swap(our_queue1);
  std::queue<int> std_queue({1, 2, 3});
  std::queue<int> std_queue1({4, 5, 6});
  std_queue.swap(std_queue1);
  while (!std_queue.empty()) {
    EXPECT_EQ(our_queue.front(), std_queue.front());
    our_queue.pop();
    std_queue.pop();
  }
}