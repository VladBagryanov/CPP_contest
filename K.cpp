#include <iostream>

void PushDp(int** dp, int size_f, int size_s, int* array_f, int* array_s) {
  for (int i = 0; i < size_f + 1; ++i) {
    dp[i][0] = 0;
  }
  for (int i = 1; i < size_s + 1; ++i) {
    dp[0][i] = 0;
  }
  for (int i = 1; i < size_f + 1; ++i) {
    for (int j = 1; j < size_s + 1; ++j) {
      if (array_f[i - 1] == array_s[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
}

void PushNop(int* array_nop, int size_f, int size_s, int* array_f, int** dp) {
  int i = size_f;
  int j = size_s;
  int count = 0;
  while (count < dp[size_f][size_s]) {
    if (dp[i][j] == dp[i - 1][j]) {
      --i;
      continue;
    }
    if (dp[i][j] == dp[i][j - 1]) {
      --j;
      continue;
    }
    array_nop[count] = array_f[i - 1];
    --i;
    --j;
    ++count;
    if (i == 0 || j == 0) {
      break;
    }
  }
}

int main() {
  int size_f;
  int size_s;
  std::cin >> size_f;
  auto array_f = new int[size_f];
  for (int i = 0; i < size_f; ++i) {
    std::cin >> array_f[i];
  }
  std::cin >> size_s;
  auto array_s = new int[size_s];
  for (int i = 0; i < size_s; ++i) {
    std::cin >> array_s[i];
  }
  auto dp = new int*[size_f + 1];
  for (int i = 0; i < size_f + 1; ++i) {
    dp[i] = new int[size_s + 1];
  }
  PushDp(dp, size_f, size_s, array_f, array_s);
  auto array_nop = new int[dp[size_f][size_s]];
  PushNop(array_nop, size_f, size_s, array_f, dp);
  for (int i = dp[size_f][size_s] - 1; i >= 0; --i) {
    std::cout << array_nop[i] << " ";
  }
  delete[] array_f;
  delete[] array_s;
  delete[] array_nop;
  for (int i = 0; i < size_f + 1; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
}