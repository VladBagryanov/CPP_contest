#include <iostream>

void PushArray(int64_t* array, int64_t n) {
  uint64_t div_2;
  uint64_t div_3;
  uint64_t minus_1;
  for (int64_t i = 2; i < n + 1; ++i) {
    div_2 = i % 2 == 0 ? array[i / 2] : i;
    div_3 = i % 3 == 0 ? array[i / 3] : i;
    minus_1 = array[i - 1];
    array[i] = std::min(div_2, std::min(div_3, minus_1)) + 1;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.tie(nullptr);
  int64_t n;
  std::cin >> n;
  auto array = new int64_t[n + 1];
  array[1] = 0;
  array[0] = 0;
  for (int i = 2; i < n + 1; ++i) {
    array[i] = -1;
  }
  PushArray(array, n);
  std::cout << array[n];
  delete[] array;
}