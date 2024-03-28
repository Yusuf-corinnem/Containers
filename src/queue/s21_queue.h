#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // CONSTRUCTORS
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);

  // DESTRUCTOR
  ~queue();

  // OPERATOR
  queue &operator=(queue &&q);

  // FUNCTIONS
  const_reference front();
  const_reference back();
  bool empty();
  size_type size() const;
  void push(const_reference value);
  void pop();
  void swap(queue &other);

 private:
  struct Node {
    Node *next_;
    Node *prev_;
    value_type value_;

    Node(const T &value = 0) : next_(nullptr), prev_(nullptr), value_(value) {}
  };

  Node *head_ = nullptr;
  Node *tail_ = nullptr;
  size_type size_ = 0;
};
}  // namespace s21

#include "s21_queue.tpp"

#endif