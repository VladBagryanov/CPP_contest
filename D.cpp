#include <iostream>

int Pred(int n, int* array) {
  if (array[n] != -1) {
    return array[n];
  }
  array[n] = 2 * Pred(n - 1, array) + 2 * Pred(n - 2, array);
  return array[n];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  auto array = new int[n + 1];
  array[0] = 1;
  array[1] = 2;
  for (int i = 2; i < n + 1; ++i) {
    array[i] = -1;
  }
  std::cout << Pred(n, array) + Pred(n - 1, array);
  delete[] array;
}