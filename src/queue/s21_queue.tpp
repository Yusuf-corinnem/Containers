namespace s21 {
// CONSTRUCTORS
template <typename value_type>
queue<value_type>::queue() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename value_type>
queue<value_type>::queue(std::initializer_list<value_type> const &items) {
  for (auto iter = items.begin(); iter != items.end(); ++iter) {
    push(*iter);
  }
}

template <typename value_type>
queue<value_type>::queue(const queue &q) {
  Node *temp = q.head_;
  while (temp) {
    push(temp->value_);
    temp = temp->prev_;
  }
}

template <typename value_type>
queue<value_type>::queue(queue &&q) {
  head_ = q.head_;
  tail_ = q.tail_;
  size_ = q.size_;
  q.head_ = nullptr;
  q.tail_ = nullptr;
  q.size_ = 0;
}

// DESTRUCTOR
template <typename value_type>
queue<value_type>::~queue() {
  while (!empty()) pop();
}

// OPERATOR
template <typename value_type>
queue<value_type> &queue<value_type>::operator=(queue &&q) {
  if (this != &q) {
    this->~queue();
    head_ = q.head_;
    tail_ = q.tail_;
    size_ = q.size_;
    q.head_ = nullptr;
    q.tail_ = nullptr;
    q.size_ = 0;
  }
  return *this;
}

// FUNCTIONS
template <typename value_type>
typename queue<value_type>::const_reference queue<value_type>::front() {
  if (empty()) throw "Stack is empty";
  return head_->value_;
}

template <typename value_type>
typename queue<value_type>::const_reference queue<value_type>::back() {
  if (empty()) throw "Stack is empty";
  return tail_->value_;
}

template <typename value_type>
bool queue<value_type>::empty() {
  return head_ == nullptr ? true : false;
}

template <typename value_type>
typename queue<value_type>::size_type queue<value_type>::size() const {
  return size_;
}

template <typename value_type>
void queue<value_type>::push(const_reference value) {
  Node *ptr = new Node(value);
  if (tail_ != nullptr) {
    tail_->prev_ = ptr;
    ptr->next_ = tail_;
  }
  if (empty()) {
    head_ = ptr;
  }
  tail_ = ptr;
  ++size_;
}

template <typename value_type>
void queue<value_type>::pop() {
  if (head_ != nullptr) {
    Node *ptr = head_->prev_;
    delete head_;
    head_ = ptr;
    --size_;
  }
}

template <typename value_type>
void queue<value_type>::swap(queue &other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
}
}  // namespace s21