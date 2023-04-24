#include <iostream>

void MaxSearch(int64_t** dp, int64_t i, int64_t j, int64_t*** prev, int64_t* array_f) {
  prev[i][j][1] = j;
  dp[i][j] = 1;
  for (int64_t k = 1; k < i; ++k) {
    if (array_f[k - 1] < array_f[i - 1] && dp[i][j] < dp[k][j] + 1) {
      dp[i][j] = dp[k][j] + 1;
      prev[i][j][0] = k;
    }
  }
}

void PushDp(int64_t** dp, int64_t size_f, int64_t* array_f, int64_t size_s, int64_t* array_s, int64_t*** prev) {
  for (int64_t i = 0; i < size_f + 1; i++) {
    dp[i][0] = 0;
  }
  for (int64_t i = 0; i < size_s + 1; i++) {
    dp[0][i] = 0;
  }
  for (int64_t i = 1; i < size_f + 1; i++) {
    for (int64_t j = 1; j < size_s + 1; j++) {
      if (array_f[i - 1] == array_s[j - 1]) {
        MaxSearch(dp, i, j, prev, array_f);
      } else {
        dp[i][j] = dp[i][j - 1];
        prev[i][j][0] = i;
        prev[i][j][1] = j - 1;
      }
    }
  }
  int64_t y = size_s;
  int64_t x = 1;
  for (int64_t j = 1; j < size_f + 1; ++j) {
    if (dp[x][y] < dp[j][y]) {
      x = j;
    }
  }
  int64_t count = dp[x][y];
  if (dp[x][y] == 0) {
    std::cout << 0;
    return;
  }
  auto print_array = new int64_t[count];
  int64_t size = 0;
  while (size != count) {
    if (prev[x][y][0] != x) {
      print_array[size] = array_f[x - 1];
      ++size;
    }
    int64_t new_x = prev[x][y][0];
    int64_t new_y = prev[x][y][1];
    x = new_x;
    y = new_y;
  }
  std::cout << count << "\n";
  for (int64_t i = size - 1; i >= 0; --i) {
    std::cout << print_array[i] << " ";
  }
  delete[] print_array;
}

int main() {
  int64_t size_f;
  int64_t size_s;
  std::cin >> size_f;
  auto array_f = new int64_t[size_f];
  for (int64_t i = 0; i < size_f; ++i) {
    std::cin >> array_f[i];
  }
  std::cin >> size_s;
  auto array_s = new int64_t[size_s];
  for (int64_t i = 0; i < size_s; ++i) {
    std::cin >> array_s[i];
  }
  auto dp = new int64_t*[size_f + 1];
  for (int64_t j = 0; j < size_f + 1; ++j) {
    dp[j] = new int64_t[size_s + 1];
  }
  auto prev = new int64_t**[size_f + 1];
  for (int64_t j = 0; j < size_f + 1; ++j) {
    prev[j] = new int64_t*[size_s + 1];
    for (int64_t k = 0; k < size_s + 1; ++k) {
      prev[j][k] = new int64_t[2];
    }
  }
  PushDp(dp, size_f, array_f, size_s, array_s, prev);
  delete[] array_f;
  delete[] array_s;
  for (int64_t i = 0; i < size_f + 1; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
  for (int64_t i = 0; i < size_f + 1; ++i) {
    for (int64_t j = 0; j < size_s + 1; ++j) {
      delete[] prev[i][j];
    }
    delete[] prev[i];
  }
  delete[] prev;
}