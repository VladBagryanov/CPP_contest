#include <iostream>
#include <cstring>

int LCS(const char* first_str, const char* second_str) {
  int len_first = strlen(first_str);
  int len_second = len_first;
  auto dp = new int*[len_first + 1];
  for (int i = 0; i < len_first + 1; ++i) {
    dp[i] = new int[len_second + 1];
  }
  for (int i = 0; i < len_first + 1; ++i) {
    dp[i][0] = 0;
  }
  for (int i = 0; i < len_second + 1; ++i) {
    dp[0][i] = 0;
  }
  for (int i = 1; i < len_first + 1; ++i) {
    for (int j = 1; j < len_second + 1; ++j) {
      if (first_str[i - 1] == second_str[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int res = dp[len_first][len_second];
  for (int i = 0; i < len_first + 1; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
  return res;
}

int LenPalindrom(const char* str) {
  int len = strlen(str);
  auto reversed_str = new char[len];
  for (int i = 0; i < len; ++i) {
    reversed_str[i] = str[len - i - 1];
  }
  int res = LCS(str, reversed_str);
  delete[] reversed_str;
  return len - res;
}

int main() {
  auto first_str = new char[10000];
  std::cin >> first_str;
  std::cout << LenPalindrom(first_str);
  delete[] first_str;
}