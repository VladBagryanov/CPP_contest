#include <iostream>
#include <cstring>

struct Node {
  Node* prev = nullptr;
  int value;
};

class Stack {
 private:
  Node* last_ = nullptr;
  size_t size_ = 0;

 public:
  void Push(int val);
  int Pop();
  void Clear();
  int Back() const;
  int Size() const;
};

void Stack::Push(int val) {
  auto new_node = new Node;
  new_node->value = val;
  new_node->prev = this->last_;
  this->last_ = new_node;
  ++this->size_;
}

int Stack::Pop() {
  if (this->size_ == 0) {
    return 0;
  }
  int temp = this->last_->value;
  Node* last__for_delete = this->last_;
  this->last_ = this->last_->prev;
  delete last__for_delete;
  --this->size_;
  return temp;
}

int Stack::Back() const {
  if (this->size_ == 0) {
    return 0;
  }
  return this->last_->value;
}

int Stack::Size() const {
  return this->size_;
}

void Stack::Clear() {
  if (this->size_ > 0) {
    this->Pop();
    this->Clear();
  }
  delete this->last_;
}

int main() {
  char string[100000];
  std::cin.getline(string, 100000);
  Stack stack;
  uint64_t size = strlen(string);
  for (uint64_t i = 0; i < size; ++i) {
    if (string[i] != ' ') {
      if (string[i] >= '0' && string[i] <= '9') {
        stack.Push(string[i] - '0');
      } else {
        int second_value = stack.Pop();
        int first_value = stack.Pop();
        if (string[i] == '+') {
          stack.Push(first_value + second_value);
        } else if (string[i] == '-') {
          stack.Push(first_value - second_value);
        } else {
          stack.Push(first_value * second_value);
        }
      }
    }
  }
  std::cout << stack.Back();
  stack.Clear();
}