#include "s21_list.h"

namespace s21 {
// CONSTRUCTORS
template <class value_type>
list<value_type>::list() : head_(nullptr), tail_(nullptr), size_(0) {}

template <class value_type>
list<value_type>::list(size_type n) {
  for (size_t i = 0; i < n; ++i) {
    push_back(0);
  }
}

template <class value_type>
list<value_type>::list(std::initializer_list<value_type> const& items) {
  for (auto iter = items.begin(); iter != items.end(); ++iter) {
    push_back(*iter);
  }
}

template <class value_type>
list<value_type>::list(const list& l) {
  Node* temp = l.head_;
  while (temp) {
    push_back(temp->value_);
    temp = temp->next_;
  }
}

template <class value_type>
list<value_type>::list(list&& l) {
  *this = std::move(l);
}

// DESTRUCTOR
template <class value_type>
list<value_type>::~list() {
  while (head_ != nullptr) {
    pop_back();
  }
}

// OPERATOR
template <class value_type>
list<value_type>& list<value_type>::operator=(list&& l) {
  if (this != &l) {
    this->~list();
    head_ = l.head_;
    tail_ = l.tail_;
    size_ = l.size_;
    l.head_ = nullptr;
    l.tail_ = nullptr;
    l.size_ = 0;
  }
  return *this;
}

// ITERATORS

template <class value_type>
typename list<value_type>::iterator list<value_type>::begin() {
  return this->head_;
}

template <class value_type>
typename list<value_type>::iterator list<value_type>::end() {
  return tail_;
}

template <class value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  if (pos == begin()) {
    push_front(value);
    return begin();
  } else {
    Node* new_node = new Node(value);
    Node* ptr = head_;
    while (ptr && pos != iterator(ptr)) {
      ptr = ptr->next_;
      if (!ptr) {
        delete new_node;
        return end();
      }
    }
    if (ptr->prev_) {
      ptr->prev_->next_ = new_node;
    }
    new_node->prev_ = ptr->prev_;
    new_node->next_ = ptr;
    ptr->prev_ = new_node;
    size_++;
    return iterator(new_node);
  }
}

// FUNCTIONS
template <class value_type>
typename list<value_type>::const_reference list<value_type>::front() {
  if (empty()) throw "List is empty";
  return head_->value_;
}

template <class value_type>
typename list<value_type>::const_reference list<value_type>::back() {
  if (empty()) throw "List is empty";
  return tail_->value_;
}

template <class value_type>
bool list<value_type>::empty() {
  return head_ == nullptr;
}

template <class value_type>
typename list<value_type>::size_type list<value_type>::size() {
  return size_;
}

template <class value_type>
typename list<value_type>::size_type list<value_type>::max_size() {
  return std::numeric_limits<size_type>::max() /
         sizeof(typename list<value_type>::Node) / 2;
}

template <class value_type>
void s21::list<value_type>::clear() {
  size_ = 0;
}

template <class value_type>
void s21::list<value_type>::erase(iterator pos) {
  if (pos == begin()) {
    pop_front();
  } else {
    Node* ptr = head_;
    while (pos != iterator(ptr)) {
      ptr = ptr->next_;
    }
    if (ptr->next_) {
      ptr->prev_->next_ = ptr->next_;
      ptr->next_->prev_ = ptr->prev_;
    } else {
      ptr->prev_->next_ = nullptr;
    }
    delete ptr;
    size_--;
  }
}

template <class value_type>
void s21::list<value_type>::push_back(const_reference value) {
  Node* ptr = new Node(value);
  if (head_ == nullptr) {
    head_ = ptr;
  } else {
    ptr->prev_ = tail_;
    tail_->next_ = ptr;
  }
  tail_ = ptr;
  tail_->next_ = nullptr;
  ++size_;
}

template <class value_type>
void s21::list<value_type>::pop_back() {
  if (tail_) {
    Node* ptr = tail_->prev_;
    delete tail_;
    tail_ = ptr;
    if (tail_)
      tail_->next_ = nullptr;
    else
      head_ = nullptr;
    --size_;
  }
}

template <class value_type>
void s21::list<value_type>::push_front(const_reference value) {
  Node* ptr = new Node(value);
  if (tail_ == nullptr) {
    tail_ = ptr;
  } else {
    ptr->next_ = head_;
    head_->prev_ = ptr;
  }
  head_ = ptr;
  head_->prev_ = nullptr;
  ++size_;
}

template <class value_type>
void s21::list<value_type>::pop_front() {
  if (head_) {
    Node* ptr = head_->next_;
    delete head_;
    head_ = ptr;
    if (head_)
      head_->prev_ = nullptr;
    else
      tail_ = nullptr;
    --size_;
  }
}

template <class value_type>
void s21::list<value_type>::swap(list& other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
}

template <class value_type>
void s21::list<value_type>::merge(list& other) {
  Node* temp = other.head_;
  while (temp) {
    push_back(temp->value_);
    temp = temp->next_;
  }
  sort();
}

template <class value_type>
void s21::list<value_type>::splice(const_iterator pos, list& other) {
  if (!(other.empty())) {
    iterator tempIt = pos;
    for (auto it = other.begin(); it != other.end(); ++it) {
      insert(tempIt, *it);
    }
    other.clear();
  }
}

template <class value_type>
void s21::list<value_type>::reverse() {
  Node* ptr = tail_;
  while (ptr) {
    std::swap(ptr->next_, ptr->prev_);
    ptr = ptr->next_;
  }
  std::swap(tail_, head_);
}

template <class value_type>
void s21::list<value_type>::unique() {
  Node* ptr = head_;
  while (ptr && ptr->next_) {
    if (ptr->value_ == ptr->next_->value_) {
      Node* duplicate = ptr->next_;
      ptr->next_ = duplicate->next_;
      delete duplicate;
    } else {
      ptr = ptr->next_;
    }
  }
}

template <class value_type>
void s21::list<value_type>::sort() {
  bool swap;
  Node* ptr;
  // Проверяем, является ли список пустым
  if (head_ == nullptr) {
    return;
  }
  do {
    swap = false;
    ptr = head_;
    while (ptr->next_) {
      if (ptr->value_ > ptr->next_->value_) {
        // Обмениваем значения смежных узлов
        value_type temp = ptr->value_;
        ptr->value_ = ptr->next_->value_;
        ptr->next_->value_ = temp;
        swap = true;
      }
      ptr = ptr->next_;
    }
  } while (swap);
}
}  // namespace s21