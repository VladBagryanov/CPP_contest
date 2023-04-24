#include <iostream>

struct Node {
  int key;
  Node* left = nullptr;
  Node* right = nullptr;
  int height = 1;
};

class Tree {
 private:
  Node* root_ = nullptr;

 public:
  void Insert(int key);
  Node* InsertNode(Node* node, int key);
  Node* Root();
  Node* RightRotate(Node* y);
  Node* LeftRotate(Node* x);
  Node* Balancing(Node* node);
};

Node* Tree::Root() {
  return this->root_;
}

int Height(const Node* node) {
  return node == nullptr ? 0 : node->height;
}

Node* Tree::RightRotate(Node* y) {
  bool check_root = y == root_;
  Node* x = y->left;
  y->left = x->right;
  x->right = y;
  y->height = std::max(Height(y->left), Height(y->right)) + 1;
  x->height = std::max(Height(x->left), Height(x->right)) + 1;
  if (check_root) {
    root_ = x;
  }
  return x;
}

Node* Tree::LeftRotate(Node* x) {
  bool check_root = x == root_;
  Node* y = x->right;
  x->right = y->left;
  y->left = x;
  x->height = std::max(Height(x->left), Height(x->right)) + 1;
  y->height = std::max(Height(y->left), Height(y->right)) + 1;
  if (check_root) {
    root_ = y;
  }
  return y;
}

int BalanceFactor(const Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return Height(node->right) - Height(node->left);
}

Node* Tree::Balancing(Node* node) {
  node->height = std::max(Height(node->left), Height(node->right)) + 1;
  if (BalanceFactor(node) == 2) {
    if (BalanceFactor(node->right) == -1) {
      node->right = this->RightRotate(node->right);
    }
    return this->LeftRotate(node);
  }
  if (BalanceFactor(node) == -2) {
    if (BalanceFactor(node->left) == 1) {
      node->left = this->LeftRotate(node->left);
    }
    return this->RightRotate(node);
  }
  return node;
}

Node* Tree::InsertNode(Node* node, int key) {
  if (this->root_ == nullptr) {
    auto new_node = new Node;
    new_node->key = key;
    this->root_ = new_node;
    return new_node;
  }
  if (node == nullptr) {
    auto new_node = new Node;
    new_node->key = key;
    return new_node;
  }
  if (key < node->key) {
    node->left = this->InsertNode(node->left, key);
  } else if (key > node->key) {
    node->right = this->InsertNode(node->right, key);
  }
  return this->Balancing(node);
}

int LowerBound(Node* node, int val, int border) {
  if (node == nullptr) {
    return border;
  }
  if (node->key == val) {
    return val;
  }
  if (node->key < val) {
    return LowerBound(node->right, val, border);
  }
  if (node->key > val) {
    border = node->key;
    return LowerBound(node->left, val, border);
  }
  return border;
}

void Clear(Node* node) {
  if (node == nullptr) {
    return;
  }
  Clear(node->right);
  Clear(node->left);
  delete node;
}

int main() {
  int count;
  std::cin >> count;
  char oper;
  char last_oper = '+';
  int val;
  Tree tree;
  int val_last;
  for (int i = 0; i < count; ++i) {
    std::cin >> oper >> val;
    if (oper == '?') {
      val_last = LowerBound(tree.Root(), val, -1);
      std::cout << val_last << "\n";
      last_oper = '?';
    }
    if (oper == '+' and last_oper == '+') {
      tree.InsertNode(tree.Root(), val);
      last_oper = '+';
    } else if (oper == '+' and last_oper != '+') {
      tree.InsertNode(tree.Root(), (val + val_last) % 1000000000);
      last_oper = '+';
    }
  }
  Clear(tree.Root());
}