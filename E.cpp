#include <iostream>

int64_t PredCount(int64_t n, int64_t** array, int64_t number) {
  if (array[number][n] != -1) {
    return array[number][n];
  }
  if (number == 9) {
    array[9][n] = PredCount(n - 1, array, 4) + PredCount(n - 1, array, 2);
  }
  if (number == 8) {
    array[8][n] = PredCount(n - 1, array, 1) + PredCount(n - 1, array, 3);
  }
  if (number == 7) {
    array[7][n] = PredCount(n - 1, array, 6) + PredCount(n - 1, array, 2);
  }
  if (number == 6) {
    array[6][n] = PredCount(n - 1, array, 7) + PredCount(n - 1, array, 1) + PredCount(n - 1, array, 0);
  }
  if (number == 5) {
    array[5][n] = 0;
  }
  if (number == 3) {
    array[3][n] = PredCount(n - 1, array, 4) + PredCount(n - 1, array, 8);
  }
  if (number == 2) {
    array[2][n] = PredCount(n - 1, array, 7) + PredCount(n - 1, array, 9);
  }
  if (number == 1) {
    array[1][n] = PredCount(n - 1, array, 6) + PredCount(n - 1, array, 8);
  }
  if (number == 0) {
    array[0][n] = PredCount(n - 1, array, 6) + PredCount(n - 1, array, 4);
  }
  if (number == 4) {
    array[4][n] = PredCount(n - 1, array, 9) + PredCount(n - 1, array, 3) + PredCount(n - 1, array, 0);
  }
  return array[number][n];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.tie(nullptr);
  int64_t n;
  std::cin >> n;
  auto array = new int64_t*[10];
  for (int64_t i = 0; i < 10; ++i) {
    array[i] = new int64_t[n];
    array[i][0] = i == 0 || i == 8 ? 0 : 1;
  }
  for (int64_t i = 0; i < 10; ++i) {
    for (int64_t j = 1; j < n; ++j) {
      array[i][j] = -1;
    }
  }
  int64_t sum = 0;
  for (int64_t i = 0; i < 10; ++i) {
    sum += PredCount(n - 1, array, i);
  }
  std::cout << sum;
  for (int i = 0; i < 10; ++i) {
    delete[] array[i];
  }
  delete[] array;
}