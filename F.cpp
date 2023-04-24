#include <iostream>

void PushDp(int64_t** dp, int64_t road, int64_t direct) {
  for (int64_t i = 0; i < direct; ++i) {
    for (int64_t j = 0; j < road; ++j) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int64_t i = 0; i < direct; ++i) {
    for (int64_t j = 0; j < road; ++j) {
      if (i < direct - 1) {
        dp[i + 1][j] += dp[i][j];
      }
      if (j < road - 1) {
        dp[i][j + 1] += dp[i][j];
      }
      if (i < direct - 1 && j < road - 1) {
        dp[i + 1][j + 1] += dp[i][j];
      }
    }
  }
}

int main() {
  int64_t road;
  int64_t direct;
  std::cin >> road >> direct;
  auto dp = new int64_t*[direct];
  for (int64_t i = 0; i < direct; ++i) {
    dp[i] = new int64_t[road];
  }
  PushDp(dp, road, direct);
  std::cout << dp[direct - 1][road - 1];
  for (int64_t i = 0; i < direct; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
}