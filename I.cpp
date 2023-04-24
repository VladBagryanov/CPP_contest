#include <iostream>

int64_t LeftBinSearch(int64_t h, int64_t w, int64_t n) {
  int64_t right = n * (h + w + 1);
  int64_t left = -1;
  int64_t mid;
  while (left < right - 1) {
    mid = left + (right - left) / 2;
    if ((mid / w) * (mid / h) < n) {
      left = mid;
    } else {
      right = mid;
    }
  }
  if (((left + 1) / w) * ((left + 1) / h) >= n) {
    return left + 1;
  }
  return left + 2;
}

int main() {
  int64_t w;
  int64_t h;
  int64_t n;
  std::cin >> w;
  std::cin >> h;
  std::cin >> n;
  int64_t c = LeftBinSearch(h, w, n);
  std::cout << c;
}