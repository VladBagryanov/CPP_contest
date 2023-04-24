#ifndef HEAP
#define HEAP

template <class T>
void Swap(T& first, T& second) {
  T value = first;
  first = second;
  second = value;
}

template <class T, class U>
void SiftDown(T* begin, T* end, U idx) {
  U left = 2 * idx + 1;
  U right = 2 * idx + 2;
  U largest = idx;
  if (left < end - begin && begin[largest] < begin[left]) {
    largest = left;
  }
  if (right < end - begin && begin[largest] < begin[right]) {
    largest = right;
  }
  if (largest < idx || idx < largest) {
    Swap(begin[idx], begin[largest]);
    SiftDown(begin, end, largest);
  }
}

template <class T>
void MakeHeap(T* begin, T* end) {
  for (T* i = (end - begin - 1) / 2 + begin; i > begin - 1; --i) {
    SiftDown(begin, end, i - begin);
  }
}

template <class T>
void SortHeap(T* begin, T* end) {
  for (T* i = end - 1; i > begin; --i) {
    Swap(begin[0], i[0]);
    --end;
    SiftDown(begin, end, 0);
  }
}

#endif