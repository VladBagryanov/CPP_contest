#include <iostream>

void PushDp(int64_t* dp, int size, int* array) {
  for (int i = 0; i < size; ++i) {
    dp[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (array[j] < array[i]) {
        dp[i] += dp[j];
        dp[i] %= 1000000;
      }
    }
  }
  int64_t sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += dp[i];
    sum %= 1000000;
  }
  std::cout << sum;
}

int main() {
  int size;
  std::cin >> size;
  auto array = new int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
  auto dp = new int64_t[size];
  PushDp(dp, size, array);
  delete[] dp;
  delete[] array;
}