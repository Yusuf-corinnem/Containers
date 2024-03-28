#ifndef _S21_SET_H_
#define _S21_SET_H_

#include "../tree/s21_tree.h"
namespace s21 {
template <class Key>
class set : public tree<Key, Key> {
 public:
  // MEMBER TYPE
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename tree<Key, Key>::iterator;
  using const_iterator = typename tree<Key, Key>::const_iterator;
  using size_type = size_t;

  // CONSTRUCTORS
  set();
  set(std::initializer_list<value_type> const &items);
  set(const set &s);
  set(set &&s);

  // DESTRUCTOR
  ~set() = default;

  // OPERATOR
  set &operator=(set &&s);
};
}  // namespace s21

#include "s21_set.tpp"

#endif  // _S21_SET_H_