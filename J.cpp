#include <iostream>
#include <algorithm>

int64_t PushDp(int64_t* array, int64_t n) {
  if (n == 2) {
    return array[2] - array[1];
  }
  if (n == 3) {
    return array[3] - array[1];
  }
  auto dp = new int64_t[n + 1];
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = array[2] - array[1];
  dp[3] = array[3] - array[1];
  for (int64_t i = 4; i < n + 1; ++i) {
    dp[i] = std::min(dp[i - 1], dp[i - 2]) + array[i] - array[i - 1];
  }
  int64_t count = dp[n];
  delete[] dp;
  return count;
}
int main() {
  int64_t n;
  std::cin >> n;
  auto array = new int64_t[n + 1];
  array[0] = 0;
  for (int64_t i = 1; i < n + 1; ++i) {
    std::cin >> array[i];
  }
  std::sort(array, array + n + 1);
  int64_t size = PushDp(array, n);
  std::cout << size;
  delete[] array;
}