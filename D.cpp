#include <iostream>
void Create(int n);

void Del(int n);

void Create(int n) {
  if (n == 1) {
    std::cout << 1 << " ";
    return;
  }
  if (n == 0) {
    return;
  }
  Create(n - 1);
  std::cout << n << " ";
  Del(n - 1);
}

void Del(int n) {
  if (n == 1) {
    std::cout << -1 << " ";
    return;
  }
  if (n == 0) {
    return;
  }
  Create(n - 1);
  std::cout << -n << " ";
  Del(n - 1);
}
int main() {
  int n;
  std::cin >> n;
  for (int i = n; i > 0; i = i - 2) {
    Create(i - 1);
    std::cout << i << " ";
  }
}