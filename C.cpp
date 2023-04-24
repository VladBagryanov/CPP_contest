#include <iostream>

uint64_t Max(uint64_t height, uint64_t width) {
  if (height > width) {
    return height;
  }
  return width;
}

int main() {
  uint64_t count;
  std::cin >> count;
  uint64_t sum = 0;
  uint64_t width;
  uint64_t height;
  for (uint64_t i = 0; i < count; ++i) {
    std::cin >> width >> height;
    sum += Max(width, height);
  }
  std::cout << sum;
}