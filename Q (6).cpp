#include <iostream>

void Transiton(int size_f, int size_s, int height, int width, int** array, int pos[2]) {
  int new_pos[2]{pos[0], pos[1]};
  for (int i = pos[0]; i < height + pos[0] && i < size_f; ++i) {
    for (int j = pos[1]; j < width + pos[1] && j < size_s; ++j) {
      if (array[i][j] > array[new_pos[0]][new_pos[1]]) {
        new_pos[0] = i;
        new_pos[1] = j;
      }
    }
  }
  if (new_pos[0] == pos[0] && new_pos[1] == pos[1]) {
    std::cout << pos[0] << " " << pos[1];
    return;
  }
  pos[0] = new_pos[0];
  pos[1] = new_pos[1];
  Transiton(size_f, size_s, height, width, array, pos);
}

int main() {
  int size_f;
  int size_s;
  int height;
  int width;
  std::cin >> size_f >> size_s >> height >> width;
  auto array = new int*[size_f];
  for (int i = 0; i < size_f; ++i) {
    array[i] = new int[size_s];
  }
  for (int i = 0; i < size_f; ++i) {
    for (int j = 0; j < size_s; ++j) {
      std::cin >> array[i][j];
    }
  }
  int pos[2]{};
  Transiton(size_f, size_s, height, width, array, pos);
  for (int i = 0; i < size_f; ++i) {
    delete[] array[i];
  }
  delete[] array;
}