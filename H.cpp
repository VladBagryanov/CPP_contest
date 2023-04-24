#include <iostream>
#include <cstring>

char Reverse(char symbol) {
  if (symbol == ')') {
    return '(';
  }
  if (symbol == ']') {
    return '[';
  }
  return '{';
}

bool ChekerTruePSP(char* array) {
  int len = strlen(array);
  char array_open[1000000];
  int size_open = 0;
  for (int i = 0; i < len; ++i) {
    if ((array[i] == '(') || (array[i] == '[') || (array[i] == '{')) {
      array_open[size_open] = array[i];
      ++size_open;
    } else {
      if ((size_open <= 0) || (array_open[size_open - 1] != Reverse(array[i]))) {
        return false;
      }
      --size_open;
    }
  }
  return size_open == 0;
}
int main() {
  char array[1000000];
  std::cin >> array;
  bool chek = ChekerTruePSP(array);
  if (chek) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
}