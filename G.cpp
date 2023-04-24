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

int Game(Deque first_player, Deque second_player, int& count) {
  for (int i = 0; i < 100000; ++i) {
    if (first_player.Size() == 0) {
      second_player.Clear();
      return 2;
    }
    if (second_player.Size() == 0) {
      first_player.Clear();
      return 1;
    }
    ++count;
    if ((first_player.Back() > second_player.Back() && (first_player.Back() != 9 || second_player.Back() != 0)) ||
        (first_player.Back() == 0 && second_player.Back() == 9)) {
      first_player.PushFront(first_player.Back());
      first_player.PopBack();
      first_player.PushFront(second_player.Back());
      second_player.PopBack();
    } else {
      second_player.PushFront(first_player.Back());
      first_player.PopBack();
      second_player.PushFront(second_player.Back());
      second_player.PopBack();
    }
  }
  first_player.Clear();
  second_player.Clear();
  return 0;
}

int main() {
  Deque first_player;
  Deque second_player;
  int count = 0;
  int value;
  for (int i = 0; i < 5; ++i) {
    std::cin >> value;
    first_player.PushFront(value);
  }
  for (int i = 0; i < 5; ++i) {
    std::cin >> value;
    second_player.PushFront(value);
  }
  int winner = Game(first_player, second_player, count);
  if (winner == 0) {
    std::cout << "botva ";
  } else if (winner == 1) {
    std::cout << "first " << count;
  } else {
    std::cout << "second " << count;
  }
}