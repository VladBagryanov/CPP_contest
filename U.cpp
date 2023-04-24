#include <iostream>
#include <cstring>
#include <cmath>

void Binary(int len, char* str_digits) {
  int rem = 0;
  int rem_sled = 0;
  for (int i = 0; i < len; ++i) {
    rem_sled = ((str_digits[i] - '0') % 2) * 10;
    str_digits[i] = ((str_digits[i] - '0') + rem) / 2 + '0';
    rem = rem_sled;
  }
  if (str_digits[0] == '0') {
    ++str_digits;
    --len;
  }
  if (len > 0) {
    Binary(len, str_digits);
  }
  std::cout << rem / 10;
}

void Change(char* str) {
  auto str_digits = new char[255];
  int i = 0;
  int len = strlen(str);
  int count;
  while (i < len) {
    count = 0;
    while (i < len && (str[i] < '0' || str[i] > '9')) {
      std::cout << str[i];
      ++i;
    }
    while (i < len && str[i] >= '0' && str[i] <= '9') {
      str_digits[count] = str[i];
      ++count;
      ++i;
    }
    if (count > 0) {
      Binary(count, str_digits);
    }
  }
  delete[] str_digits;
}

int main() {
  char in_str[255];
  std::cin.getline(in_str, 255);
  Change(in_str);
}