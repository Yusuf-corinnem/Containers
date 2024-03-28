namespace s21 {
// CONSTRUCTORS
template <class Key, class Value>
map<Key, Value>::map() : tree<Key, Value>() {}

template <class Key, class Value>
map<Key, Value>::map(std::initializer_list<value_type> const &items) {
  for (const auto &item : items) {
    tree<Key, Value>::insert(item.first, item.second);
  }
}

template <class Key, class Value>
map<Key, Value>::map(const map &m) : tree<Key, Value>(m) {}

template <class Key, class Value>
map<Key, Value>::map(map &&m) : tree<Key, Value>(std::move(m)) {}

template <class Key, class Value>
map<Key, Value> &map<Key, Value>::operator=(map &&m) {
  if (this != &m) {
    tree<Key, Value>::operator=(std::move(m));
  }
  return *this;
}
}  // namespace s21