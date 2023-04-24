#include <iostream>

void ArrayCreat(char** array, int size1, int size2) {
  for (int i = 0; i < size1; ++i) {
    array[i] = new char[size2];
  }
}
void ArrayInput(char** array, int size1, int size2) {
  for (int i = 0; i < size1; ++i) {
    for (int j = 0; j < size2; ++j) {
      std::cin >> array[i][j];
    }
  }
}

int CountGorizontLine(char** array, int n, int m) {
  int mult_gorizont;
  int count_gorizont = 0;
  for (int i = 0; i < n; ++i) {
    mult_gorizont = 1;
    for (int j = 0; j < m; ++j) {
      if (array[i][j] == '0') {
        mult_gorizont = 0;
        break;
      }
    }
    count_gorizont += mult_gorizont;
  }
  return count_gorizont;
}

int CountVerticallLine(char** array, int n, int m) {
  int mult_vertical;
  int count_vertical = 0;
  for (int i = 0; i < m; ++i) {
    mult_vertical = 1;
    for (int j = 0; j < n; ++j) {
      if (array[j][i] == '0') {
        mult_vertical = 0;
        break;
      }
    }
    count_vertical += mult_vertical;
  }
  return count_vertical;
}

int CountDeltaGor(char** array, int size_ver) {
  int first_str = -1;
  int second_str = -1;
  for (int i = 0; i < size_ver; ++i) {
    if (first_str != -1 && array[i][0] == '1') {
      second_str = i;
      break;
    }
    if (first_str == -1 && array[i][0] == '1') {
      first_str = i;
    }
  }
  return second_str - first_str;
}

int CountDeltaVer(char** array, int size_gor) {
  int first_str = -1;
  int second_str = -1;
  for (int i = 0; i < size_gor; ++i) {
    if (first_str != -1 && array[0][i] == '1') {
      second_str = i;
      break;
    }
    if (first_str == -1 && array[0][i] == '1') {
      first_str = i;
    }
  }
  return second_str - first_str;
}

int main() {
  int size_ver;
  int size_gor;
  std::cin >> size_ver;
  std::cin >> size_gor;
  auto array = new char*[size_ver];
  ArrayCreat(array, size_ver, size_gor);
  ArrayInput(array, size_ver, size_gor);
  int count_ver = CountVerticallLine(array, size_ver, size_gor);
  int count_gor = CountGorizontLine(array, size_ver, size_gor);
  int delta_gor = CountDeltaGor(array, size_ver);
  int delta_ver = CountDeltaVer(array, size_gor);
  if (size_ver > 1 && size_gor > 1 && count_ver >= 1 && count_gor >= 1) {
    std::cout << "Square";
  } else if (size_ver > 1 and size_gor > 1 and count_ver > 1 and delta_ver <= size_ver) {
    std::cout << "Vertical line";
  } else if (size_ver > 1 and size_gor > 1 and count_gor > 1 and delta_gor <= size_gor) {
    std::cout << "Line";
  } else {
    std::cout << "?";
  }
  for (int i = 0; i < size_ver; ++i) {
    delete[] array[i];
  }
  delete[] array;
}