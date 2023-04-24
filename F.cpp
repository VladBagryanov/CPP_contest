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

int main() {
  int k;
  std::cin >> k;
  char command[20];
  Deque deque;
  for (int i = 0; i < k; ++i) {
    std::cin >> command;
    if (strcmp(command, "push_front") == 0) {
      int value;
      std::cin >> value;
      deque.PushFront(value);
      std::cout << "ok"
                << "\n";
    }
    if (strcmp(command, "push_back") == 0) {
      int value;
      std::cin >> value;
      deque.PushBack(value);
      std::cout << "ok"
                << "\n";
    }
    if (strcmp(command, "back") == 0) {
      if (deque.Size() == 0) {
        std::cout << "error"
                  << "\n";
      } else {
        std::cout << deque.Back() << "\n";
      }
    }
    if (strcmp(command, "front") == 0) {
      if (deque.Size() == 0) {
        std::cout << "error"
                  << "\n";
      } else {
        std::cout << deque.Front() << "\n";
      }
    }
    if (strcmp(command, "pop_front") == 0) {
      if (deque.Size() == 0) {
        std::cout << "error"
                  << "\n";
      } else {
        std::cout << deque.PopFront() << "\n";
      }
    }
    if (strcmp(command, "pop_back") == 0) {
      if (deque.Size() == 0) {
        std::cout << "error"
                  << "\n";
      } else {
        std::cout << deque.PopBack() << "\n";
      }
    }
    if (strcmp(command, "clear") == 0) {
      deque.Clear();
      std::cout << "ok"
                << "\n";
    }
    if (strcmp(command, "exit") == 0) {
      std::cout << "bye"
                << "\n";
      break;
    }
    if (strcmp(command, "size") == 0) {
      std::cout << deque.Size() << "\n";
    }
  }
  deque.Clear();
}