#include <iostream>

void PushDp(int* dp, int size, int* array, int* prev) {
  for (int i = 0; i < size; ++i) {
    dp[i] = 1;
    prev[i] = -1;
    for (int j = 0; j < i; ++j) {
      if (array[j] < array[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        prev[i] = j;
      }
    }
  }
  int pos = 0;
  int length = dp[0];
  for (int i = 0; i < size; ++i) {
    if (dp[i] > length) {
      pos = i;
      length = dp[i];
    }
  }
  auto print_nvp = new int[length];
  int size_print = 0;
  while (pos != -1) {
    print_nvp[size_print] = array[pos];
    pos = prev[pos];
    ++size_print;
  }
  for (int i = size_print - 1; i >= 0; --i) {
    std::cout << print_nvp[i] << " ";
  }
  delete[] print_nvp;
}

int main() {
  int size;
  std::cin >> size;
  auto array = new int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
  auto dp = new int[size];
  auto prev = new int[size];
  PushDp(dp, size, array, prev);
  delete[] dp;
  delete[] prev;
  delete[] array;
}