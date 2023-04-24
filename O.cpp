#include <iostream>

void PushDp(int64_t** dp, int64_t size, int64_t heft, int64_t* array_cost, int64_t* array_heft) {
  for (int64_t i = 0; i < size + 1; ++i) {
    dp[i][0] = 0;
  }
  for (int64_t i = 0; i < heft + 1; ++i) {
    dp[0][i] = 0;
  }
  for (int64_t i = 1; i < size + 1; ++i) {
    for (int64_t j = 1; j < heft + 1; ++j) {
      if (array_heft[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - array_heft[i - 1]] + array_cost[i - 1]);
      }
    }
  }
}

int64_t PushNop(int64_t* array_nop, int64_t size, int64_t heft, int64_t* array_heft, int64_t** dp) {
  int64_t i = size;
  int64_t j = heft;
  int64_t count = 0;
  while (i != 0 && j != 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      --i;
      continue;
    }
    array_nop[count] = i;
    j -= array_heft[i - 1];
    --i;
    ++count;
    if (i <= 0 || j <= 0) {
      break;
    }
  }
  return count;
}

int main() {
  int64_t size;
  int64_t heft;
  std::cin >> size >> heft;
  auto array_heft = new int64_t[size];
  for (int64_t i = 0; i < size; ++i) {
    std::cin >> array_heft[i];
  }
  auto array_cost = new int64_t[size];
  for (int64_t i = 0; i < size; ++i) {
    std::cin >> array_cost[i];
  }
  auto dp = new int64_t*[size + 1];
  for (int64_t i = 0; i < size + 1; ++i) {
    dp[i] = new int64_t[heft + 1];
  }
  PushDp(dp, size, heft, array_cost, array_heft);
  auto array_nop = new int64_t[size];
  int64_t count = PushNop(array_nop, size, heft, array_heft, dp);
  for (int64_t i = count - 1; i >= 0; --i) {
    std::cout << array_nop[i] << "\n";
  }
  delete[] array_cost;
  delete[] array_heft;
  delete[] array_nop;
  for (int64_t i = 0; i < size + 1; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
}