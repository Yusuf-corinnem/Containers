#ifndef _S21_LIST_H_
#define _S21_LIST_H_

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {
template <class T>
class list {
 public:
  // MEMBER TYPE
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

 private:
  struct Node {
    Node *next_;
    Node *prev_;
    value_type value_;
    explicit Node(const T &value)
        : next_(nullptr), prev_(nullptr), value_(value){};
  };
  Node *head_ = nullptr;
  Node *tail_ = nullptr;
  int size_ = 0;

  template <class value_type>
  class ListConstIterator;

  template <class value_type>
  class ListIterator {
    friend class ListConstIterator<value_type>;

   public:
    ListIterator() { ptr_ = nullptr; }
    ListIterator(Node *ptr) { ptr_ = ptr; }
    value_type &operator*() { return ptr_->value_; }
    bool operator==(ListIterator other) { return this->ptr_ == other.ptr_; }
    bool operator!=(ListIterator other) { return this->ptr_ != other.ptr_; }
    ListIterator &operator++() {
      ptr_ = ptr_->next_;
      return *this;
    }
    ListIterator operator++(int) {
      ListIterator tmp = *this;
      ptr_ = ptr_->next_;
      return tmp;
    }

   private:
    Node *ptr_ = nullptr;
  };
  template <class value_type>
  class ListConstIterator : public ListIterator<value_type> {
   public:
    ListConstIterator(ListIterator<value_type> other)
        : ListIterator<value_type>(other) {}
    const_reference operator*() const {
      return ListIterator<value_type>::operator*();
    }
  };

 public:
  using iterator = ListIterator<value_type>;
  using const_iterator = ListConstIterator<value_type>;
  //   CONSTRUCTORS
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);

  // DESTRUCTOR
  ~list();

  // OPERATOR
  list &operator=(list &&l);

  // ITERATORS
  iterator begin();
  iterator end();
  iterator insert(iterator pos, const_reference value);

  // FUNCTIONS
  const_reference front();
  const_reference back();
  bool empty();
  size_type size();
  size_type max_size();
  void clear();
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();
};

}  // namespace s21

#include "s21_list.tpp"

#endif  //_S21_LIST_H_
