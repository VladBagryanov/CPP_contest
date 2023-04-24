#include <iostream>

int64_t Pred(int64_t n, int64_t* array) {
  if (array[n] != -1) {
    return array[n];
  }
  array[n] = Pred(n - 1, array) + Pred(n - 2, array);
  return array[n];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.tie(nullptr);
  int64_t n;
  std::cin >> n;
  auto array = new int64_t[n + 2];
  array[1] = 1;
  array[2] = 2;
  for (int64_t i = 3; i < n + 2; ++i) {
    array[i] = -1;
  }
  std::cout << Pred(n + 1, array);
  delete[] array;
}