#include <stack>

#include "gtest/gtest.h"
#include "tests.h"

TEST(StackConstructors, Default) {
  s21::stack<int> our_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(our_stack.empty(), std_stack.empty());
}

TEST(StackConstructors, InitList) {
  s21::stack<int> our_stack({1, 2, 3});
  std::stack<int> std_stack({1, 2, 3});
  EXPECT_EQ(our_stack.top(), std_stack.top());
}

TEST(StackConstructors, Copy) {
  s21::stack<int> our_stack({3, 4});
  s21::stack<int> our_stack1(our_stack);
  std::stack<int> std_stack({3, 4});
  std::stack<int> std_stack1(std_stack);
  EXPECT_EQ(our_stack1.top(), std_stack1.top());
}

TEST(StackConstructors, Move) {
  s21::stack<int> our_stack({1, 2});
  std::stack<int> std_stack({1, 2});
  s21::stack<int> our_stack1(std::move(our_stack));
  std::stack<int> std_stack1(std::move(std_stack));
  EXPECT_EQ(our_stack1.top(), std_stack1.top());
}

TEST(StackOperator, Move) {
  s21::stack<int> our_stack({1, 2});
  std::stack<int> std_stack({1, 2});
  s21::stack<int> our_stack1 = std::move(our_stack);
  std::stack<int> std_stack1 = std::move(std_stack);
  EXPECT_EQ(our_stack1.top(), std_stack1.top());
}

TEST(StackFunctions, Push) {
  s21::stack<int> our_stack;
  our_stack.push(1);
  our_stack.push(2);
  std::stack<int> std_stack;
  std_stack.push(1);
  std_stack.push(2);
  EXPECT_EQ(our_stack.top(), std_stack.top());
}

TEST(StackFunctions, Pop) {
  s21::stack<int> our_stack({1, 2});
  our_stack.pop();
  std::stack<int> std_stack({1, 2});
  std_stack.pop();
  EXPECT_EQ(our_stack.top(), std_stack.top());
}

TEST(StackFunctions, Swap) {
  s21::stack<int> our_stack({1, 2, 3});
  s21::stack<int> our_stack1({4, 5, 6});
  our_stack.swap(our_stack1);
  std::stack<int> std_stack({1, 2, 3});
  std::stack<int> std_stack1({4, 5, 6});
  std_stack.swap(std_stack1);
  EXPECT_EQ(our_stack.top(), std_stack.top());
}
