#include <iostream>

void ArrayCreat(int** array, int size1, int size2) {
  for (int i = 0; i < size1; ++i) {
    array[i] = new int[size2];
  }
}

void ArrayInput(int** array, int size1, int size2) {
  for (int i = 0; i < size1; ++i) {
    for (int j = 0; j < size2; ++j) {
      std::cin >> array[i][j];
    }
  }
}

void ArrayDel(int** array, int size) {
  for (int i = 0; i < size; ++i) {
    delete[] array[i];
  }
  delete[] array;
}

void CountNeighborOutside(int** array, int** array_hp, int n) {
  for (int i = 1; i < n - 1; ++i) {
    array_hp[0][i] = array[0][i - 1] + array[1][i] + array[0][i + 1] + array[1][i - 1] + array[1][i + 1];
    array_hp[n - 1][i] =
        array[n - 1][i - 1] + array[n - 2][i] + array[n - 1][i + 1] + array[n - 2][i - 1] + array[n - 2][i + 1];
    array_hp[i][0] = array[i - 1][0] + array[i + 1][0] + array[i][1] + array[i - 1][1] + array[i + 1][1];
    array_hp[i][n - 1] =
        array[i - 1][n - 1] + array[i + 1][n - 1] + array[i][n - 2] + array[i - 1][n - 2] + array[i + 1][n - 2];
  }
  array_hp[0][0] = array[0][1] + array[1][0] + array[1][1];
  array_hp[0][n - 1] = array[1][n - 2] + array[1][n - 1] + array[0][n - 2];
  array_hp[n - 1][0] = array[n - 1][1] + array[n - 2][0] + array[n - 2][1];
  array_hp[n - 1][n - 1] = array[n - 1][n - 2] + array[n - 2][n - 1] + array[n - 2][n - 2];
}

void CountNeighborInside(int** array, int** array_hp, int n) {
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      array_hp[i][j] = array[i - 1][j - 1] + array[i][j - 1] + array[i + 1][j - 1];
      array_hp[i][j] += array[i - 1][j + 1] + array[i][j + 1] + array[i + 1][j + 1];
      array_hp[i][j] += array[i - 1][j] + array[i + 1][j];
    }
  }
}

void ConversionArray(int** array, int** array_hp, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (array_hp[i][j] == 3) {
        array[i][j] = 1;
      } else {
        if (array_hp[i][j] != 2) {
          array[i][j] = 0;
        }
      }
    }
  }
}

void ArrayPrint(int** array, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      std::cout << array[i][j] << " ";
    }
    std::cout << array[i][n - 1] << "\n";
  }
}

int main() {
  int n;
  int t;
  std::cin >> n;
  std::cin >> t;
  auto array = new int*[n];
  ArrayCreat(array, n, n);
  ArrayInput(array, n, n);
  auto array_hp = new int*[n];
  ArrayCreat(array_hp, n, n);
  if (n == 1) {
    std::cout << 0;
  } else {
    for (int k = 0; k < t; ++k) {
      CountNeighborOutside(array, array_hp, n);
      CountNeighborInside(array, array_hp, n);
      ConversionArray(array, array_hp, n);
    }
    ArrayPrint(array, n);
  }
  ArrayDel(array, n);
  ArrayDel(array_hp, n);
}