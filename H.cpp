#include <iostream>

int main() {
  auto array_str = new char[100000];
  auto array_rev = new char[100000];
  char cheker = '0';
  int count = 0;
  while (cheker != '#') {
    std::cin >> cheker;
    if (cheker == '#') {
      break;
    }
    if (count % 2 == 0) {
      array_str[count / 2] = cheker;
    } else {
      array_rev[count / 2] = cheker;
    }
    count += 1;
  }
  int count_str;
  int count_rev;
  count_str = count / 2 + count % 2;
  count_rev = count / 2;
  for (int i = 0; i < count_str; ++i) {
    std::cout << array_str[i];
  }
  for (int i = count_rev; i > 0; --i) {
    std::cout << array_rev[i - 1];
  }
  delete[] array_str;
  delete[] array_rev;
}