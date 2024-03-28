namespace s21 {
// CONSTRUCTORS
template <class Key>
multiset<Key>::multiset() : tree<Key, Key>() {}

template <class Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    tree<Key, Key>::addMultiset(*i, *i);
  }
}

template <class Key>
multiset<Key>::multiset(const multiset &ms) : tree<Key, Key>(ms) {}

template <class Key>
multiset<Key>::multiset(multiset &&ms) : tree<Key, Key>(std::move(ms)) {}

template <class Key>
multiset<Key> &multiset<Key>::operator=(multiset &&ms) {
  if (this != &ms) {
    tree<Key, Key>::operator=(std::move(ms));
  }
  return *this;
}
template <class Key>
void multiset<Key>::merge(multiset &other) {
  tree<Key, Key>::mergeMultiset(other);
}

}  // namespace s21