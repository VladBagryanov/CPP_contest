#include <iostream>
void Swap(int64_t *array_use, int size_global, int64_t *array_use_global) {
  for (int i = 0; i < size_global; ++i) {
    array_use_global[i] = array_use[i];
  }
}

void NulArray(int64_t *array, int size) {
  for (int i = 0; i < size; ++i) {
    array[i] = 0;
  }
}
int SumArray(int64_t *array, int size) {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += array[i];
  }
  return sum;
}
void Chek(int64_t m, int64_t *array, int size, int &min_count, int64_t *array_use, int64_t *array_use_global,
          int size_global) {
  if (m < 0 or size < 0) {
    return;
  }
  if (m == 0) {
    int c = SumArray(array_use, size_global);
    if (c < min_count) {
      min_count = c;
      Swap(array_use, size_global, array_use_global);
    }
    return;
  }
  if (size == 0) {
    return;
  }
  array_use[size - 1] = 2;
  Chek(m - 2 * array[size - 1], array, size - 1, min_count, array_use, array_use_global, size_global);
  array_use[size - 1] = 1;
  Chek(m - array[size - 1], array, size - 1, min_count, array_use, array_use_global, size_global);
  array_use[size - 1] = 0;
  Chek(m, array, size - 1, min_count, array_use, array_use_global, size_global);
}
int main() {
  int64_t m;
  int n;
  std::cin >> m;
  std::cin >> n;
  auto array = new int64_t[n];
  auto array_use = new int64_t[n];
  auto array_use_global = new int64_t[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> array[i];
  }
  NulArray(array_use, n);
  NulArray(array_use_global, n);
  int min_count = 31;
  Chek(m, array, n, min_count, array_use, array_use_global, n);
  if (2 * SumArray(array, n) < m) {
    std::cout << -1;
  } else {
    if (min_count == 31) {
      std::cout << 0;
    } else {
      std::cout << min_count << "\n";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < array_use_global[i]; ++j) {
          std::cout << array[i] << " ";
        }
      }
    }
  }
  delete[] array;
  delete[] array_use;
  delete[] array_use_global;
}