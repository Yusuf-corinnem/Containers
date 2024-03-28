#ifndef _S21_MAP_H_
#define _S21_MAP_H_

#include "../tree/s21_tree.h"
namespace s21 {
template <class Key, class Value>
class map : public tree<Key, Value> {
 public:
  class MapIterator;
  class MapConstIterator;

 public:
  // MEMBER TYPE
  using key_type = Key;
  using mapped_type = Value;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename tree<Key, Value>::iterator;
  using const_iterator = typename tree<Key, Value>::const_iterator;
  using size_type = size_t;

  // CONSTRUCTORS
  map();
  map(std::initializer_list<value_type> const &items);
  map(const map &m);
  map(map &&m);

  // DESTRUCTOR
  ~map() = default;

  // OPERATORS
  map &operator=(map &&m);

  class MapConstIterator : public tree<Key, Value>::ConstTreeIterator {
   public:
    friend class map;
    MapConstIterator() : tree<Key, Value>::ConstTreeIterator() {}
    MapConstIterator(typename tree<Key, Value>::Node *node)
        : tree<Key, Value>::ConstTreeIterator(node) {}

    std::pair<const Key, Value> operator*() {
      return std::make_pair(
          tree<Key, Value>::ConstTreeIterator::current_->key_,
          tree<Key, Value>::ConstTreeIterator::current_->data_);
    }
    typename tree<Key, Value>::ConstTreeIterator &operator=(
        const typename tree<Key, Value>::ConstTreeIterator &other) {
      tree<Key, Value>::ConstTreeIterator::operator=(other);
      return *this;
    }
  };

  class MapIterator : public MapConstIterator {
   public:
    MapIterator() : MapConstIterator() {}
    MapIterator(typename tree<Key, Value>::Node *node)
        : MapConstIterator(node) {}
    std::pair<const Key, Value> operator*() {
      return MapConstIterator::operator*();
    }
    typename tree<Key, Value>::ConstTreeIterator &operator=(
        const typename tree<Key, Value>::ConstTreeIterator &other) {
      MapConstIterator::operator=(other);
      return *this;
    }
  };
};
}  // namespace s21

#include "s21_map.tpp"

#endif  // _S21_MAP_H_