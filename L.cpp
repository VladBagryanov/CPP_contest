#include <iostream>

void Swap(int64_t* array, int64_t a, int64_t b) {
  int64_t c = array[a];
  array[a] = array[b];
  array[b] = c;
}

int64_t Portition(int64_t* array, int64_t left, int64_t right) {
  int pivot_val = array[right];
  int pivot_point = left;
  for (int i = left; i < right; ++i) {
    if (array[i] <= pivot_val) {
      Swap(array, i, pivot_point);
      pivot_point++;
    }
  }
  Swap(array, pivot_point, right);
  return pivot_point;
}

void QuickSort(int64_t* array, int64_t left, int64_t right) {
  if (left >= right) {
    return;
  }
  int64_t pivot = Portition(array, left, right);
  QuickSort(array, left, pivot - 1);
  QuickSort(array, pivot + 1, right);
}

void InputArray(int64_t* array, int64_t size) {
  for (int64_t i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
}

void DeleteRepeat(int64_t* array, int64_t* array_new, int64_t& size) {
  int64_t size_new = 1;
  array_new[0] = array[0];
  for (int64_t i = 1; i < size; ++i) {
    if (array[i] != array[i - 1]) {
      array_new[size_new] = array[i];
      ++size_new;
    }
  }
  size = size_new;
}

bool Chek(int64_t* array1, int64_t size, int64_t* array2) {
  bool chek = true;
  for (int i = 0; i < size; ++i) {
    chek = array1[i] == array2[i];
    if (!chek) {
      break;
    }
  }
  return chek;
}

int main() {
  int64_t size1;
  std::cin >> size1;
  auto array1 = new int64_t[size1];
  InputArray(array1, size1);
  int64_t size2;
  std::cin >> size2;
  auto array2 = new int64_t[size2];
  InputArray(array2, size2);
  QuickSort(array1, 0, size1 - 1);
  QuickSort(array2, 0, size2 - 1);
  auto array1_new = new int64_t[size1];
  auto array2_new = new int64_t[size2];
  DeleteRepeat(array1, array1_new, size1);
  DeleteRepeat(array2, array2_new, size2);
  if (size1 == size2) {
    bool chek = Chek(array1_new, size1, array2_new);
    if (chek) {
      std::cout << "YES";
    } else {
      std::cout << "NO";
    }
  } else {
    std::cout << "NO";
  }
  delete[] array1;
  delete[] array2;
  delete[] array2_new;
  delete[] array1_new;
}