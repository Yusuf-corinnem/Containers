#ifndef _S21_MULTISET_H_
#define _S21_MULTISET_H_

#include "../tree/s21_tree.h"
namespace s21 {
template <class Key>
class multiset : public tree<Key, Key> {
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
  multiset();
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &ms);
  multiset(multiset &&ms);

  // DESTRUCTOR
  ~multiset() = default;

  // OPERATOR
  multiset &operator=(multiset &&ms);

  // FUNCTION
  void merge(multiset &other);
};
}  // namespace s21

#include "s21_multiset.tpp"

#endif  // _S21_MULTISET_H_