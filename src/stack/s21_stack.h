#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

namespace s21 {
template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // CONSTRUCTORS
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);

  // DESTRUCTOR
  ~stack();

  // OPERATOR
  stack &operator=(stack &&s);

  // FUNCTIONS
  const_reference top();
  bool empty();
  size_type size() const;
  void push(const_reference value);
  void pop();
  void swap(stack &other);

 private:
  struct Node {
    value_type value_;
    Node *prev_;

    Node(const T &value = 0) : value_(value), prev_(nullptr) {}
  };
  Node *head_ = nullptr;
  size_type size_ = 0;
};
}  // namespace s21

#include "s21_stack.tpp"  //stok

#endif  // _STACK_H_
