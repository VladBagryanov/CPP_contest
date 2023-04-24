#include <iostream>
#include <algorithm>

struct Cell {
  uint64_t value;
  uint64_t count = 1;
};
uint64_t DeleteteRepeat(uint64_t* array, uint64_t size, Cell* new_array) {
  uint64_t size_new = 0;
  uint64_t i = 0;
  while (i < size) {
    new_array[size_new].value = array[i];
    new_array[size_new].count = 1;
    ++i;
    while (i < size && array[i] == new_array[size_new].value) {
      ++new_array[size_new].count;
      ++i;
    }
    ++size_new;
  }
  return size_new;
}

uint64_t Counter(Cell* array, uint64_t size, uint64_t k) {
  uint64_t count = 0;
  uint64_t count_one_entry = 0;
  uint64_t count_two_entry = 0;
  while (count_one_entry < size - 1 && array[count_one_entry + 1].value <= k * array[0].value) {
    ++count_one_entry;
    if (array[count_one_entry].count >= 2) {
      ++count_two_entry;
    }
  }
  uint64_t c = array[0].count >= 2;
  uint64_t d = array[0].count >= 3;
  count += count_one_entry * (count_one_entry - 1) * 3 + 3 * count_two_entry + 3 * c * count_one_entry + d;
  for (uint64_t index = 1; index < size; ++index) {
    while (index + count_one_entry < size && array[index + count_one_entry].value <= k * array[index].value) {
      ++count_one_entry;
      if (array[count_one_entry + index - 1].count >= 2) {
        ++count_two_entry;
      }
    }
    --count_one_entry;
    count_two_entry -= array[index].count >= 2;
    c = array[index].count >= 2;
    d = array[index].count >= 3;
    count += count_one_entry * (count_one_entry - 1) * 3 + 3 * count_two_entry + 3 * c * count_one_entry + d;
  }
  return count;
}

int main() {
  uint64_t size;
  uint64_t k;
  std::cin >> size >> k;
  auto input_array = new uint64_t[size];
  for (uint64_t i = 0; i < size; ++i) {
    std::cin >> input_array[i];
  }
  std::sort(input_array, input_array + size);
  auto array = new Cell[size];
  uint64_t new_size = DeleteteRepeat(input_array, size, array);
  uint64_t count = Counter(array, new_size, k);
  std::cout << count;
  delete[] array;
  delete[] input_array;
}