#include <cstddef>
#include <iostream>
#include <cstring>

int Minimal(int first_value, int second_value) {
  return first_value > second_value ? second_value : first_value;
}

struct Node {
  Node* prev = nullptr;
  int value;
  int min;
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
  int Min() const;
};

void Stack::Push(int val) {
  auto new_node = new Node;
  new_node->value = val;
  if (this->size_ != 0) {
    new_node->min = Minimal(val, this->last_->min);
  } else {
    new_node->min = val;
  }
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
  --this->size_;
  delete last__for_delete;
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

int Stack::Min() const {
  return this->last_->min;
}

class Queue {
 private:
  Stack basic_stack_;
  Stack support_stack_;

 public:
  void Enqueue(int value);
  int Dequeue();
  void Clear();
  int Front();
  int Size() const;
  int Min() const;
};

void Queue::Enqueue(int value) {
  this->basic_stack_.Push(value);
}

int Queue::Dequeue() {
  if (this->support_stack_.Size() != 0) {
    return this->support_stack_.Pop();
  }
  while (this->basic_stack_.Size() > 0) {
    this->support_stack_.Push(this->basic_stack_.Pop());
  }
  return support_stack_.Pop();
}

int Queue::Front() {
  if (this->support_stack_.Size() != 0) {
    return this->support_stack_.Back();
  }
  while (this->basic_stack_.Size() > 0) {
    this->support_stack_.Push(this->basic_stack_.Pop());
  }
  return support_stack_.Back();
}

int Queue::Size() const {
  return this->basic_stack_.Size() + this->support_stack_.Size();
}

void Queue::Clear() {
  this->basic_stack_.Clear();
  this->support_stack_.Clear();
}

int Queue::Min() const {
  if (this->support_stack_.Size() == 0) {
    return this->basic_stack_.Min();
  }
  if (this->basic_stack_.Size() == 0) {
    return this->support_stack_.Min();
  }
  return Minimal(this->basic_stack_.Min(), this->support_stack_.Min());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.tie(nullptr);
  int k;
  std::cin >> k;
  char command[20];
  Queue queue;
  for (int i = 0; i < k; ++i) {
    std::cin >> command;
    if (strcmp(command, "enqueue") == 0) {
      int value;
      std::cin >> value;
      queue.Enqueue(value);
      std::cout << "ok"
                << "\n";
    }
    if (strcmp(command, "front") == 0) {
      if (queue.Size() == 0) {
        std::cout << "error"
                  << "\n";
      } else {
        std::cout << queue.Front() << "\n";
      }
    }
    if (strcmp(command, "dequeue") == 0) {
      if (queue.Size() == 0) {
        std::cout << "error"
                  << "\n";
      } else {
        std::cout << queue.Dequeue() << "\n";
      }
    }
    if (strcmp(command, "min") == 0) {
      if (queue.Size() == 0) {
        std::cout << "error"
                  << "\n";
      } else {
        std::cout << queue.Min() << "\n";
      }
    }
    if (strcmp(command, "clear") == 0) {
      queue.Clear();
      std::cout << "ok"
                << "\n";
    }
    if (strcmp(command, "size") == 0) {
      std::cout << queue.Size() << "\n";
    }
  }
  queue.Clear();
}