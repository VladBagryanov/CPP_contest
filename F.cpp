#include <iostream>

void Shift(int n, int begin, int end) {
  if (n == 0) {
    return;
  }
  Shift(n - 1, begin, 6 - begin - end);
  std::cout << n << " " << begin << " " << end << "\n";
  Shift(n - 1, 6 - begin - end, end);
}

int main() {
  int n;
  std::cin >> n;
  Shift(n, 1, 3);
}