#include <cstddef>
#include <iostream>
#include <cstring>

struct Node {
  Node* prev = nullptr;
  Node* sled = nullptr;
  int value;
};

class Deque {
 private:
  Node* last_ = nullptr;
  Node* first_ = nullptr;
  size_t size_ = 0;

 public:
  void PushFront(int val);
  void PushBack(int val);
  int PopFront();
  int PopBack();
  void Clear();

  int Back() const;
  int Front() const;
  int Size() const;
};

void Deque::PushFront(int val) {
  auto new_node = new Node;
  new_node->value = val;
  new_node->sled = this->first_;
  new_node->prev = nullptr;
  if (this->size_ != 0) {
    this->first_->prev = new_node;
  } else {
    this->last_ = new_node;
  }
  this->first_ = new_node;
  ++this->size_;
}

void Deque::PushBack(int val) {
  auto new_node = new Node;
  new_node->value = val;
  new_node->prev = this->last_;
  new_node->sled = nullptr;
  if (this->size_ != 0) {
    this->last_->sled = new_node;
  } else {
    this->first_ = new_node;
  }
  this->last_ = new_node;
  ++this->size_;
}

int Deque::PopBack() {
  if (this->size_ == 0) {
    return 0;
  }
  int temp = this->last_->value;
  Node* last__for_delete = this->last_;
  if (this->size_ != 1) {
    this->last_->prev->sled = nullptr;
  }
  this->last_ = this->last_->prev;
  delete last__for_delete;
  --this->size_;
  return temp;
}

int Deque::PopFront() {
  if (this->size_ == 0) {
    return 0;
  }
  int temp = this->first_->value;
  Node* first__for_delete = this->first_;
  if (this->size_ != 1) {
    this->first_->sled->prev = nullptr;
  }
  this->first_ = this->first_->sled;
  delete first__for_delete;
  --this->size_;
  return temp;
}

int Deque::Back() const {
  if (this->size_ == 0) {
    return 0;
  }
  return this->last_->value;
}

int Deque::Front() const {
  if (this->size_ == 0) {
    return 0;
  }
  return this->first_->value;
}

int Deque::Size() const {
  return this->size_;
}

void Deque::Clear() {
  if (this->size_ > 0) {
    this->PopBack();
    this->Clear();
  }
}

void Balance(Deque& first_deque, Deque& second_deque) {
  if (first_deque.Size() - second_deque.Size() == 0 || first_deque.Size() - second_deque.Size() == 1) {
    return;
  }
  if (first_deque.Size() - second_deque.Size() > 1) {
    second_deque.PushFront(first_deque.PopBack());
    Balance(first_deque, second_deque);
    return;
  }
  if (first_deque.Size() - second_deque.Size() < 0) {
    first_deque.PushBack(second_deque.PopFront());
    Balance(first_deque, second_deque);
  }
}

void PushBack(Deque& first_deque, Deque& second_deque, int value) {
  if (first_deque.Size() == 0) {
    first_deque.PushBack(value);
    return;
  }
  second_deque.PushBack(value);
  Balance(first_deque, second_deque);
}

void PushCenter(Deque& first_deque, Deque& second_deque, int value) {
  first_deque.PushBack(value);
  Balance(first_deque, second_deque);
}

int Pop(Deque& first_deque, Deque& second_deque) {
  int number = first_deque.PopFront();
  Balance(first_deque, second_deque);
  return number;
}

int main() {
  int count;
  std::cin >> count;
  Deque first_deque;
  Deque second_deque;
  int value;
  char command;
  for (int i = 0; i < count; ++i) {
    std::cin >> command;
    if (command == '+') {
      std::cin >> value;
      PushBack(first_deque, second_deque, value);
    }
    if (command == '*') {
      std::cin >> value;
      PushCenter(first_deque, second_deque, value);
    }
    if (command == '-') {
      std::cout << Pop(first_deque, second_deque) << "\n";
    }
  }
  first_deque.Clear();
  second_deque.Clear();
}