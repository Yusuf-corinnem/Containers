#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

namespace s21 {
template <class T, std::size_t N>
class array {
 public:
  // MEMBER TYPE
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // CONSTRUCTORS
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);

  // DESTRUCTOR
  ~array();

  // OPERATORS
  array &operator=(const array &a) noexcept;
  array &operator=(array &&a) noexcept;
  reference operator[](size_type pos);

  // ITERATORS
  iterator data();
  iterator begin();
  iterator end();

  // FUNCTIONS
  reference at(size_type pos);
  const_reference front();
  const_reference back();
  bool empty();
  size_type size();
  size_type max_size();
  void swap(array &other);
  void fill(const_reference value);

  void print();

 private:
  value_type array_[N] = {};
  size_type size_ = N;
};
}  // namespace s21

#include "s21_array.tpp"

#endif  // _ARRAY_H_