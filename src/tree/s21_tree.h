#ifndef _S21_TREE_H_
#define _S21_TREE_H_

#include <iostream>
#include <limits>

#include "../vector/s21_vector.h"

namespace s21 {
template <class Key, class Value>
class tree {
 public:
  class TreeIterator;
  class ConstTreeIterator;

  using iterator = TreeIterator;
  using const_iterator = ConstTreeIterator;
  using size_type = std::size_t;

 protected:
  struct Node {
    Key key_;
    Value data_;
    Node *parent_;
    Node *left_;
    Node *right_;
    explicit Node(const Key &key, const Value &data)
        : key_(key),
          data_(data),
          parent_(nullptr),
          left_(nullptr),
          right_(nullptr){};

    explicit Node(const Key &key, const Value &data, Node *parent)
        : key_(key),
          data_(data),
          parent_(parent),
          left_(nullptr),
          right_(nullptr){};
  };
  Node *root_ = nullptr;
  size_type size_ = 0;
  size_type count_duplicate_ = 0;

 public:
  class ConstTreeIterator {
    friend class tree<Key, Value>;

   public:
    ConstTreeIterator() : current_(nullptr) {}
    ConstTreeIterator(Node *node) : current_(node) {}

    Value operator*() const { return current_->data_; }

    ConstTreeIterator &operator++() {
      if (current_->right_) {
        current_ = current_->right_;
        current_ = tree_->min(current_);
      } else {
        // проверяет самого себя (по линии), когда поднимается
        while (current_->parent_ && current_ == current_->parent_->right_) {
          current_ = current_->parent_;
        }
        current_ = current_->parent_;
      }
      return *this;
    }

    ConstTreeIterator &operator--() {
      if (current_->left_) {
        current_ = current_->left_;
        current_ = tree_->max(current_);
      } else {
        while (current_->parent_ && current_ == current_->parent_->left_) {
          current_ = current_->parent_;
        }
        current_ = current_->parent_;
      }
      return *this;
    }

    bool operator!=(ConstTreeIterator &other) const {
      return current_ != other.current_;
    }

   protected:
    Node *current_ = nullptr;
    s21::tree<Key, Value> *tree_;
  };

  class TreeIterator : public ConstTreeIterator {
   public:
    TreeIterator() : ConstTreeIterator() {}
    TreeIterator(Node *node) : ConstTreeIterator(node) {}
    TreeIterator &operator++() {
      ConstTreeIterator::operator++();
      return *this;
    }
    TreeIterator &operator--() {
      ConstTreeIterator::operator--();
      return *this;
    }
  };

  // CONSTRUCTORS
  tree() { root_ = nullptr; }

  tree(std::initializer_list<std::pair<Key, Value>> const &items) {
    for (const auto &item : items) {
      insert(item.first, item.second);
    }
  }

  tree(const tree &t) {
    size_ = t.size_;
    count_duplicate_ = t.count_duplicate_;
    root_ = copyTree(t.root_, nullptr);
  }

  tree(tree &&t) { *this = std::move(t); }

  tree &operator=(tree &&t) {
    if (this != &t) {
      clear(&this->root_);
      root_ = t.root_;
      size_ = t.size_;
      count_duplicate_ = t.count_duplicate_;
      t.root_ = nullptr;
      t.size_ = 0;
      t.count_duplicate_ = 0;
    }
    return *this;
  }

  // DESTRUCTOR
  ~tree() { clear(); }

  // ITERATORS
  iterator begin() {
    Node *current = root_;
    if (current == nullptr) {
      return nullptr;
    }
    return iterator(min(current));
  }

  iterator end() {
    Node *current = root_;
    if (current == nullptr) {
      return nullptr;
    }
    return ++iterator(max(current));
  }

  iterator find(const Key &key) { return iterator(findKey(key)); }

  // FUNCTIONS
  void add(Key key, Value data) {
    if (findBool(data)) return;

    Node *cell = new Node(key, data);
    Node *current = root_;

    if (root_ == nullptr) {  // root - first add
      root_ = cell;
      current = cell;
    } else {
      while (1) {
        if (cell->key_ > current->key_) {
          if (current->right_ != nullptr) {
            current = current->right_;
          } else
            break;
        } else if (cell->key_ < current->key_) {
          if (current->left_ != nullptr) {
            current = current->left_;
          } else
            break;
        }
      }
      // add
      if (cell->key_ > current->key_) {
        current->right_ = cell;
        cell->parent_ = current;
        current = cell;
      } else if (cell->key_ < current->key_) {
        current->left_ = cell;
        cell->parent_ = current;
        current = cell;
      }
    }
    size_++;
  }

  void remove(Value data) {
    Node *current = findData(data);
    if (current == nullptr) return;
    Node *tmp = current;
    int flag = 0;
    // for 2 child
    if (current->left_ != nullptr && current->right_ != nullptr) {
      tmp = current->right_;
      if (tmp->left_ == nullptr) {
        changeLink(current, tmp, flag);
      } else {
        tmp = min(tmp);
        current->data_ = tmp->data_;
        tmp->parent_->left_ = nullptr;
      }
      // for left child
    } else if (current->left_ != nullptr && current->right_ == nullptr) {
      flag = 1;
      tmp = current->left_;
      changeLink(current, tmp, flag);
      // for right child
    } else if (current->left_ == nullptr && current->right_ != nullptr) {
      tmp = current->right_;
      changeLink(current, tmp, flag);
      // for leaf
    } else if (current->left_ == nullptr && current->right_ == nullptr) {
      if (tmp->parent_->left_ == nullptr)
        tmp->parent_->right_ = nullptr;
      else if (tmp->parent_->right_ == nullptr)
        tmp->parent_->left_ = nullptr;
      else if (tmp == tmp->parent_->left_)
        tmp->parent_->left_ = nullptr;

      else if (tmp == tmp->parent_->right_)
        tmp->parent_->right_ = nullptr;
    }
    delete tmp;
    size_--;
  }

  void clear() {
    if (root_ != nullptr) clear(&root_);
    size_ = 0;
    count_duplicate_ = 0;
    root_ = nullptr;
  }

  size_type size() { return size_; }

  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(size_type) / 10;
  }

  bool empty() { return root_ == nullptr ? true : false; }

  void erase(iterator pos) { remove(*pos); }

  void swap(tree &other) {
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
    std::swap(count_duplicate_, other.count_duplicate_);
  }

  void merge(tree &other) {
    auto i2 = other.end();
    for (auto i = other.begin(); i != i2; ++i) {
      if (!findBool(*i)) {
        add(*i, *i);
      }
    }
    clear(&other.root_);
  }

  bool contains(const Key &key) { return findBool(key); }

  std::pair<iterator, bool> insert(const Value &value) {
    if (findBool(Key(value))) {
      return std::make_pair(find(Key(value)), false);
    } else {
      add(Key(value), value);
      return std::make_pair(find(Key(value)), true);
    }
  }

  std::pair<iterator, bool> insert(const Key &key, const Value &data) {
    if (findBool(key)) {
      return std::make_pair(find(key), false);
    } else {
      return insertOrAssign(key, data);
    }
  }

  std::pair<iterator, bool> insertOrAssign(const Key &key, const Value &data) {
    if (!findBool(key)) {
      add(key, data);
      return std::make_pair(find(key), true);
    } else {
      Node *current = findKey(key);
      current->data_ = data;
      return std::make_pair(find(key), false);
    }
  }

  Node *min(Node *node) {
    while (node->left_ != nullptr) {
      node = node->left_;
    }
    return node;
  }

  Node *max(Node *node) {
    while (node->right_ != nullptr) {
      node = node->right_;
    }
    return node;
  }

  // MULTISET
  size_type count(const Key &key) {
    if (findBool(key))
      return (count_duplicate_ + 1);
    else
      return 0;
  }

  iterator lower_bound(const Key &key) {
    if (!findBool(key)) return end();
    return iterator(find(key));
  }

  iterator upper_bound(const Key &key) {
    if (!findBool(key)) return end();
    iterator itr = lower_bound(key);
    while (key == *itr) {
      ++itr;
    }
    return itr;
  }

  std::pair<iterator, iterator> equal_range(int key) {
    return {lower_bound(key), upper_bound(key)};
  }

  // MAP
  Value &at(const Key &key) {
    if (findBool(key)) {
      Node *current = findKey(key);
      return current->data_;
    } else
      throw std::out_of_range("Key not found");
  }

  Value &operator[](const Key &key) {
    if (findBool(key)) {
      Node *current = findKey(key);
      return current->data_;
    } else {
      add(key, Value());
      Node *current = findKey(key);
      return current->data_;
    }
  }

  // TOOLS
 protected:
  void mergeMultiset(tree &other) {
    tree tmp = createTempTree();
    clear(&this->root_);
    auto itr_tmp = tmp.begin(), itr_tmp2 = tmp.end();
    auto itr_other = other.begin(), itr_other2 = other.end();
    while (itr_tmp != itr_tmp2 && itr_other != itr_other2) {
      if (itr_tmp != itr_tmp2) {
        addMultiset(*itr_tmp, *itr_tmp);
        ++itr_tmp;
      }
      if (itr_other != itr_other2) {
        addMultiset(*itr_other, *itr_other);
        ++itr_other;
      }
    }
    clear(&other.root_);
  }

  void addMultiset(Key key, Value data) {
    if (findBool(data)) {
      Node *cell = new Node(key, data);
      Node *current = findKey(key);
      while (current->right_) {
        current = current->right_;
      }
      current->right_ = cell;
      cell->parent_ = current;
      current = cell;
      count_duplicate_++;
    } else
      add(key, data);
  }

 private:
  Node *copyTree(Node *node, Node *parent) {
    if (node == nullptr) return nullptr;
    Node *new_node = new Node(node->key_, node->data_, parent);
    new_node->left_ = copyTree(node->left_, new_node);
    new_node->right_ = copyTree(node->right_, new_node);
    return new_node;
  }

  tree createTempTree() { return tree(*this); }

  void changeLink(Node *current, Node *tmp, int flag) {
    current->data_ = tmp->data_;
    current->key_ = tmp->key_;
    if (flag) {
      current->left_ = tmp->left_;
    } else {
      current->right_ = tmp->right_;
    }
    tmp->parent_ = current;
  }

  bool findBool(Key key) {
    Node *current = root_;
    while (current != nullptr) {
      if (key > current->key_) {
        current = current->right_;
      } else if (key < current->key_) {
        current = current->left_;
      } else if (key == current->key_) {
        return true;
      }
    }
    return false;
  }

  Node *findData(Value data) {
    Node *current = root_;
    while (current != nullptr) {
      if (data > current->data_) {
        current = current->right_;
      } else if (data < current->data_) {
        current = current->left_;
      } else if (data == current->data_) {
        return current;
      }
    }
    return nullptr;
  }

  Node *findKey(Key key) {
    Node *current = root_;
    while (current != nullptr) {
      if (key > current->key_) {
        current = current->right_;
      } else if (key < current->key_) {
        current = current->left_;
      } else if (key == current->key_) {
        return current;
      }
    }
    return nullptr;
  }

  void clear(Node **node) {
    if (*node != nullptr) {
      clear(&((*node)->left_));
      clear(&(*node)->right_);
      delete *node;
      *node = nullptr;
    }
  }
};
}  // namespace s21

#endif  // _S21_TREE_H_