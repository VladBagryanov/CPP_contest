#include <iostream>

void Counter(int64_t max_mass, int64_t max_value, int64_t* array, int64_t size, int64_t value, int64_t& count,
             bool& checker_max, bool& checker_min) {
  if (size == 1) {
    checker_min = value == max_value + 1 ? true : checker_min;
    if (value > max_value || value <= 0) {
      return;
    }
    checker_max = value == max_value ? true : checker_max;
    ++count;
    return;
  }
  if (value == 0) {
    Counter(max_mass, max_value, array, size - 1, value + array[size - 1], count, checker_max, checker_min);
    Counter(max_mass, max_value, array, size - 1, value, count, checker_max, checker_min);
    return;
  }
  Counter(max_mass, max_value, array, size - 1, value + array[size - 1], count, checker_max, checker_min);
  Counter(max_mass, max_value, array, size - 1, value, count, checker_max, checker_min);
  Counter(max_mass, max_value, array, size - 1, value - array[size - 1], count, checker_max, checker_min);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin.tie(nullptr);
  int64_t max_value;
  int64_t max_mass;
  std::cin >> max_mass >> max_value;
  max_mass = max_mass > 16 ? 16 : max_mass;
  auto array = new int64_t[max_mass];
  array[0] = 1;
  for (int64_t i = 1; i < max_mass; ++i) {
    array[i] = array[i - 1] * 4;
  }
  int64_t count = 0;
  bool checker_max = false;
  bool checker_min = false;
  Counter(max_mass, max_value, array, max_mass, 0, count, checker_max, checker_min);
  std::cout << 3 * count + !checker_max + checker_min;
  delete[] array;
}