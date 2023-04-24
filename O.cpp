#include <iostream>

uint64_t Max(uint64_t first, uint64_t second) {
  if (first > second) {
    return first;
  }
  return second;
}

struct Node {
  int value;
  Node* left;
  Node* right;
  Node* parent;
};

class Tree {
 private:
  Node* root_ = nullptr;

 public:
  Node* GetFreeNode(int value, Node* parent);
  void Insert(int value, Node* root, Node* parent);
  int Size(Node* root) const;
  Node* Root();
  void Clear(Node* temp);
  void PrintNode(Node* temp) const;
};

void Tree::PrintNode(Node* temp) const {
  if (temp->left == nullptr and temp->right == nullptr) {
    return;
  }
  if (temp->right == nullptr) {
    this->PrintNode(temp->left);
    return;
  }
  if (temp->left == nullptr) {
    this->PrintNode(temp->right);
    return;
  }
  this->PrintNode(temp->left);
  std::cout << temp->value << " ";
  this->PrintNode(temp->right);
}

void Tree::Clear(Node* temp) {
  if (temp->left != nullptr) {
    Clear(temp->left);
  }
  if (temp->right != nullptr) {
    Clear(temp->right);
  }
  delete temp;
}

Node* Tree::Root() {
  return this->root_;
}

Node* Tree::GetFreeNode(int value, Node* parent) {
  auto tmp = new Node;
  tmp->left = nullptr;
  tmp->right = nullptr;
  tmp->value = value;
  tmp->parent = parent;
  return tmp;
}

void Tree::Insert(int value, Node* root, Node* parent) {
  if (root == nullptr) {
    Node* tmp = GetFreeNode(value, parent);
    if (parent == nullptr) {
      this->root_ = tmp;
    } else if (parent->value > value) {
      parent->left = tmp;
    } else {
      parent->right = tmp;
    }
    return;
  }
  if (root->value < value) {
    Insert(value, root->right, root);
    return;
  }
  if (root->value > value) {
    Insert(value, root->left, root);
    return;
  }
}

int Tree::Size(Node* root) const {
  if (root == nullptr) {
    return 0;
  }
  return Max(Size(root->left), Size(root->right)) + 1;
}

int main() {
  Tree tree;
  int value;
  while (true) {
    std::cin >> value;
    if (value == 0) {
      break;
    }
    tree.Insert(value, tree.Root(), nullptr);
  }
  tree.PrintNode(tree.Root());
  tree.Clear(tree.Root());
}