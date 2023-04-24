#include <iostream>

bool WinCheker(int* array, int size);
void Combination(int n, int* array, int& count, int size);
bool ChekerIn(int* array, int n, int i, int size);

void Combination(int n, int* array, int& count, int size) {
  bool cheker;
  if (n != 0) {
    for (int i = 0; i < size; ++i) {
      cheker = ChekerIn(array, n, i, size);
      array[n - 1] = i;
      if (cheker) {
        Combination(n - 1, array, count, size);
      }
    }
  } else {
    cheker = WinCheker(array, size);
    if (cheker) {
      count += 1;
    }
  }
}

bool ChekerIn(int* array, int n, int i, int size) {
  bool chek = true;
  for (int j = n; j < size; ++j) {
    if (array[j] == i) {
      chek = false;
      break;
    }
  }
  return chek;
}

bool WinCheker(int* array, int size) {
  bool chek = true;
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (array[j] + j == array[i] + i or array[j] - j == array[i] - i) {
        chek = false;
        break;
      }
    }
    if (!chek) {
      break;
    }
  }
  return chek;
}

int main() {
  int count = 0;
  int n;
  std::cin >> n;
  auto array = new int[n];
  Combination(n, array, count, n);
  std::cout << count;
  delete[] array;
}