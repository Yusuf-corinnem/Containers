namespace s21 {
// CONSTRUCTORS
template <class Key>
set<Key>::set() : tree<Key, Key>() {}

template <class Key>
set<Key>::set(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    tree<Key, Key>::add(*i, *i);
  }
}

template <class Key>
set<Key>::set(const set &s) : tree<Key, Key>(s) {}

template <class Key>
set<Key>::set(set &&s) : tree<Key, Key>(std::move(s)) {}

template <class Key>
set<Key> &set<Key>::operator=(set &&s) {
  if (this != &s) {
    tree<Key, Key>::operator=(std::move(s));
  }
  return *this;
}
}  // namespace s21