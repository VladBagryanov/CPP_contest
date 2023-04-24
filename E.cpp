#include <iostream>

template <class T>
void Swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

template <class T>
T* PushHeap(T* begin, T* end) {
  T* parent = begin + (end - begin - 2) / 2;
  if (1 < end - begin and *parent < *(end - 1)) {
    Swap(*parent, *(end - 1));
    return PushHeap(begin, parent + 1);
  }
  return end - 1;
}

template <class T, class U>
int SiftDown(T* begin, T* end, U i) {
  U left = 2 * i + 1;
  U right = 2 * i + 2;
  U largest = i;
  if (left < end - begin and begin[largest] < begin[left]) {
    largest = left;
  }
  if (right < end - begin and begin[largest] < begin[right]) {
    largest = right;
  }
  if (largest < i or i < largest) {
    Swap(begin[i], begin[largest]);
    return SiftDown(begin, end, largest);
  }
  return i;
}

template <class T>
int PopHeap(T* begin, T* end) {
  Swap(*begin, *(end - 1));
  return SiftDown(begin, end - 1, 0);
}

template <class T, class U>
U SiftUp(T* begin, U i) {
  U parent = (i - 1) / 2;
  if (i >= 0 and begin[parent] < begin[i]) {
    Swap(begin[parent], begin[i]);
    return SiftUp(begin, parent);
  }
  return i;
}

template <class T, class U>
int PopIdx(T* begin, T* end, U idx) {
  Swap(begin[idx], *(end - 1));
  idx = SiftUp(begin, idx);
  return SiftDown(begin, end - 1, idx);
}

int main() {
  int max_size;
  int count;
  std::cin >> max_size >> count;
  auto array = new int[max_size];
  int size = 0;
  int val;
  int operation;
  for (int i = 0; i < count; ++i) {
    std::cin >> operation;
    if (operation == 1) {
      if (size == 0) {
        std::cout << -1 << "\n";
      } else if (size != 1) {
        std::cout << PopHeap(array, array + size) + 1 << " " << array[size - 1] << "\n";
        --size;
      } else {
        std::cout << PopHeap(array, array + size) << " " << array[size - 1] << "\n";
        --size;
      }
    }
    if (operation == 2) {
      std::cin >> val;
      if (size == max_size) {
        std::cout << -1 << "\n";
      } else {
        array[size] = val;
        ++size;
        std::cout << PushHeap(array, array + size) - array + 1;
        std::cout << "\n";
      }
    }
    if (operation == 3) {
      std::cin >> val;
      if (val > size || val == 0) {
        std::cout << -1 << "\n";
      } else {
        std::cout << array[val - 1] << "\n";
        PopIdx(array, array + size, val - 1);
        --size;
      }
    }
  }
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  delete[] array;
}