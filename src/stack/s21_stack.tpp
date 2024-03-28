namespace s21 {
// CONSTRUCTORS
template <typename value_type>
stack<value_type>::stack() : head_(nullptr), size_(0) {}

template <typename value_type>
stack<value_type>::stack(std::initializer_list<value_type> const &items) {
  for (auto iter = items.begin(); iter != items.end(); ++iter) {
    push(*iter);
  }
}

template <typename value_type>
stack<value_type>::stack(const stack &s) {
  if (s.head_ == nullptr) {
    head_ = nullptr;
    return;
  }
  value_type array[s.size()];
  int i = 0;
  Node *temp = s.head_;
  while (temp) {
    array[i] = temp->value_;
    temp = temp->prev_;
    i++;
  }
  while (i > 0) {
    push(array[i - 1]);
    i--;
  }
}

template <typename value_type>
stack<value_type>::stack(stack &&s) {
  head_ = s.head_;
  size_ = s.size_;
  s.head_ = nullptr;
  s.size_ = 0;
}

// DESTRUCTOR
template <typename value_type>
stack<value_type>::~stack() {
  while (!empty()) pop();
}

// OPERATOR
template <typename value_type>
stack<value_type> &stack<value_type>::operator=(stack &&s) {
  if (this != &s) {
    this->~stack();
    head_ = s.head_;
    size_ = s.size_;
    s.head_ = nullptr;
    s.size_ = 0;
  }
  return *this;
}

// FUNCTIONS
template <typename value_type>
typename stack<value_type>::const_reference stack<value_type>::top() {
  if (empty()) throw "Stack is empty";
  return head_->value_;
}

template <typename value_type>
bool stack<value_type>::empty() {
  return head_ == nullptr ? true : false;
}

template <typename value_type>
typename stack<value_type>::size_type stack<value_type>::size() const {
  return size_;
}

template <typename value_type>
void stack<value_type>::push(const_reference value) {
  Node *ptr = new Node(value);
  if (head_) {
    ptr->prev_ = head_;
    head_ = ptr;
  } else
    head_ = ptr;
  ++size_;
}

template <typename value_type>
void stack<value_type>::pop() {
  if (head_ != nullptr) {
    Node *ptr = head_->prev_;
    delete head_;
    head_ = ptr;
    --size_;
  }
}

template <typename value_type>
void stack<value_type>::swap(stack &other) {
  std::swap(head_, other.head_);
  std::swap(size_, other.size_);
}
}  // namespace s21