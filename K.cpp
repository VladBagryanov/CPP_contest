#include <iostream>
#include <cstring>

void Counter(const char* str, uint64_t count, uint64_t* array) {
  uint64_t len = strlen(str);
  for (uint64_t i = 0; i < len - count; ++i) {
    uint64_t j = 0;
    while (j < count && i + j + count) {
      if (str[i + j] != str[i + j + count]) {
        break;
      }
      ++j;
    }
    array[i] = j;
  }
}

void Change(uint64_t* array, uint64_t count, uint64_t len) {
  for (uint64_t i = count; i < len; ++i) {
    if (array[i - count] % count == 0 && array[i] % count) {
      array[i - count] += (array[i - count] / count) * array[i];
    } else if (array[i - count] % count == 0) {
      array[i] += (array[i - count] / count) * array[i];
    }
  }
}

int Sum(uint64_t* array, uint64_t len) {
  uint64_t sum = 0;
  for (uint64_t i = 0; i < len; ++i) {
    sum += array[i];
  }
  return sum;
}
int main() {
  char str[1000000];
  uint64_t count;
  std::cin >> count;
  std::cin >> str;
  uint64_t len_array = strlen(str) - count;
  auto array = new uint64_t[len_array];
  Counter(str, count, array);
  Change(array, count, len_array);
  std::cout << Sum(array, len_array);
  delete[] array;
}