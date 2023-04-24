#include <iostream>
#include <algorithm>

void PushDp(int* dp, int size, int* array, int* prev, int* pos) {
  int length = 0;
  pos[0] = -1;
  dp[0] = -1000000;
  for (int i = 1; i < size + 1; ++i) {
    dp[i] = 1000000;
  }
  for (int i = 0; i < size; ++i) {
    int j = std::lower_bound(dp, dp + size, array[i]) - dp;
    if (array[i] < dp[j] && dp[j - 1] < array[i]) {
      dp[j] = array[i];
      pos[j] = i;
      prev[i] = pos[j - 1];
      length = std::max(length, j);
    }
  }
  std::cout << length;
}

int main() {
  int size;
  std::cin >> size;
  auto array = new int[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
  auto dp = new int[size + 1];
  auto prev = new int[size];
  auto pos = new int[size + 1];
  PushDp(dp, size, array, prev, pos);
  delete[] dp;
  delete[] prev;
  delete[] array;
  delete[] pos;
}