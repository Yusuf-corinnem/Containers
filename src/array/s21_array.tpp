namespace s21 {
// CONSTRUCTORS
template <class T, std::size_t N>
array<T, N>::array() : size_(N) {}

template <class T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  for (auto iter = items.begin(), i = 0; iter != items.end(); ++iter, ++i) {
    array_[i] = *iter;
  }
}

template <class T, std::size_t N>
array<T, N>::array(const array &a) {
  *this = a;
}

template <class T, std::size_t N>
array<T, N>::array(array &&a) {
  *this = std::move(a);
}

// DESTRUCTOR
template <class T, std::size_t N>
array<T, N>::~array() {
  size_ = 0;
}

// OPERATORS
template <class T, std::size_t N>
array<T, N> &array<T, N>::operator=(const array &a) noexcept {
  std::copy(a.array_, a.array_ + N, array_);
  return *this;
}

template <class T, std::size_t N>
array<T, N> &array<T, N>::operator=(array &&a) noexcept {
  for (size_t i = 0; i < N; ++i) {
    array_[i] = std::move(a.array_[i]);
    a.array_[i] = 0;
  }
  return *this;
}

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  return array_[pos];
}

// ITERATORS
template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::data() {
  return N > 0 ? &array_[0] : 0;
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return N > 0 ? &array_[0] : 0;
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return N > 0 ? &array_[N] : 0;
}

// FUNCTIONS
template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= N) throw std::out_of_range("Current element outside the array");
  return array_[pos];
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
  if (empty()) throw "Array is empty";
  return array_[0];
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
  if (empty()) throw "Array is empty";
  return array_[N - 1];
}

template <class T, std::size_t N>
bool array<T, N>::empty() {
  return N > 0 ? false : true;
}

template <class T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() {
  return size_;
}

template <class T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
  return N;
}

template <class T, std::size_t N>
void array<T, N>::swap(array &other) {
  std::swap(array_, other.array_);
  std::swap(size_, other.size_);
}

template <class T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_t i = 0; i < N; ++i) {
    array_[i] = value;
  }
}

template <class T, std::size_t N>
void array<T, N>::print() {
  for (size_t i = 0; i < N; ++i) {
    std::cout << array_[i];
  }
  std::cout << std::endl;
}
}  // namespace s21