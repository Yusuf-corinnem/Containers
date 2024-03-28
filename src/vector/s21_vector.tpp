#include <vector>

#include "s21_vector.h"

namespace s21 {
// CONSTRUCTORS
template <class value_type>
vector<value_type>::vector() : size_(0), buf_(0) {}

template <class value_type>
vector<value_type>::vector(size_type n) {
  vector_ = new value_type[n];
  size_ = n;
  buf_ = n;
}

template <class value_type>
vector<value_type>::vector(std::initializer_list<value_type> const &items) {
  for (auto iter = items.begin(); iter != items.end(); ++iter) {
    push_back(*iter);
  }
}

template <class value_type>
vector<value_type>::vector(const vector &v) {
  vector_ = new value_type[v.buf_];
  *this = v;
}

template <class value_type>
vector<value_type>::vector(vector &&v) {
  *this = std::move(v);
}

// DESTRUCTOR
template <class value_type>
vector<value_type>::~vector() {
  delete[] vector_;
  size_ = 0;
  buf_ = 0;
  vector_ = nullptr;
}

// OPERATOR
template <class value_type>
vector<value_type> &vector<value_type>::operator=(const vector &v) noexcept {
  std::copy(v.vector_, v.vector_ + v.size_, vector_);
  size_ = v.size_;
  buf_ = v.buf_;
  return *this;
}

template <class value_type>
vector<value_type> &vector<value_type>::operator=(vector &&v) noexcept {
  if (this != &v) {
    for (size_t i = 0; i < v.size(); ++i) {
      push_back(v.vector_[i]);
      v.vector_[i] = 0;
    }
    v.size_ = 0, v.buf_ = 0;
    delete[] v.vector_;
    v.vector_ = nullptr;
  }
  return *this;
}

template <class value_type>
typename vector<value_type>::reference vector<value_type>::operator[](
    size_type pos) {
  return vector_[pos];
}

// ITERATORS
template <class value_type>
typename vector<value_type>::iterator vector<value_type>::begin() {
  return size_ > 0 ? &vector_[0] : 0;
}

template <class value_type>
typename vector<value_type>::iterator vector<value_type>::end() {
  return size_ > 0 ? &vector_[size_] : 0;
}

template <class value_type>
typename vector<value_type>::iterator vector<value_type>::insert(
    iterator pos, const_reference value) {
  size_type position = pos - &vector_[0];
  vector_[position] = value;
  return &vector_[position];
}

// FUNCTIONS
template <class value_type>
typename vector<value_type>::reference vector<value_type>::at(size_type pos) {
  if (pos >= buf_) throw std::out_of_range("Current element outside the array");
  return vector_[pos];
}

template <class value_type>
typename vector<value_type>::const_reference vector<value_type>::front() {
  if (empty()) throw "Array is empty";
  return vector_[0];
}

template <class value_type>
typename vector<value_type>::const_reference vector<value_type>::back() {
  if (empty()) throw "Array is empty";
  return vector_[size_ - 1];
}

template <class value_type>
typename vector<value_type>::iterator vector<value_type>::data() {
  if (empty()) throw "Array is empty";
  return &vector_[0];
}

template <class value_type>
bool vector<value_type>::empty() {
  return vector_ == nullptr ? true : false;
}

template <class value_type>
typename vector<value_type>::size_type vector<value_type>::size() {
  return size_;
}

template <class value_type>
typename vector<value_type>::size_type vector<value_type>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
}

template <class value_type>
typename vector<value_type>::size_type vector<value_type>::capacity() {
  return buf_;
}

template <typename value_type>
void vector<value_type>::shrink_to_fit() {
  value_type *new_vector_ = new value_type[size_];
  std::copy(vector_, vector_ + size_, new_vector_);
  delete[] vector_;
  vector_ = new_vector_;
  buf_ = size_;
}

template <class value_type>
void vector<value_type>::clear() {
  size_ = 0;
}

template <class value_type>
void vector<value_type>::erase(iterator pos) {
  if (pos > end()) pos = end();
  if (pos < begin()) pos = begin();
  for (iterator i = pos; i < end(); ++i) {
    *i = *(i + 1);
  }
  size_--;
}

template <class value_type>
void vector<value_type>::push_back(const_reference value) {
  if (size_ == buf_) reserve(buf_ ? buf_ * 2 : 1);
  vector_[size_++] = value;
}

template <typename value_type>
void vector<value_type>::reserve(size_type size) {  // Кондишка
  if (size > buf_) {
    value_type *new_vector_ = new value_type[size];
    std::copy(vector_, vector_ + size_, new_vector_);
    delete[] vector_;
    vector_ = new_vector_;
    buf_ = size;
  }
}

template <class value_type>
void vector<value_type>::pop_back() {
  size_--;
}

template <class value_type>
void vector<value_type>::swap(vector &other) {
  std::swap(vector_, other.vector_);
  std::swap(size_, other.size_);
  std::swap(buf_, other.buf_);
}

}  // namespace s21
