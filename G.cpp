#include <iostream>

void ShiftAC(int n);
void ShiftCA(int n);

void ShiftAC(int n) {
  if (n == 0) {
    return;
  }
  if (n == 1) {
    std::cout << 1 << " " << 1 << " " << 3 << "\n";
    return;
  }
  ShiftAC(n - 1);
  std::cout << n << " " << 1 << " " << 2 << "\n";
  ShiftCA(n - 1);
  std::cout << n << " " << 2 << " " << 3 << "\n";
  ShiftAC(n - 1);
}

void ShiftCA(int n) {
  if (n == 0) {
    return;
  }
  if (n == 1) {
    std::cout << 1 << " " << 3 << " " << 1 << "\n";
    return;
  }
  ShiftCA(n - 1);
  std::cout << n << " " << 3 << " " << 2 << "\n";
  ShiftAC(n - 1);
  std::cout << n << " " << 2 << " " << 1 << "\n";
  ShiftCA(n - 1);
}

int main() {
  int n;
  std::cin >> n;
  ShiftAC(n);
}