#ifndef MSORT
#define MSORT

template <class T>
void Swap(T& first_value, T& second_value) {
  T save_value = first_value;
  first_value = second_value;
  second_value = save_value;
}

template <class T>
void Merge(T* begin_a, T* end_a, T* begin_b, T* end_b) {
  int len_a = 0;
  int len_b = 0;
  int len_c = 0;
  auto begin_c = new T[(end_a - begin_a) + (end_b - begin_b)];
  while (end_a - begin_a > len_a and end_b - begin_b > len_b) {
    if (*(begin_b + len_b) < *(begin_a + len_a)) {
      begin_c[len_c] = *(begin_b + len_b);
      ++len_b;
    } else {
      begin_c[len_c] = *(begin_a + len_a);
      ++len_a;
    }
    ++len_c;
  }
  while (end_a - begin_a > len_a) {
    begin_c[len_c] = *(begin_a + len_a);
    ++len_c;
    ++len_a;
  }
  while (end_b - begin_b > len_b) {
    begin_c[len_c] = *(begin_b + len_b);
    ++len_c;
    ++len_b;
  }
  for (int i = 0; i < end_b - begin_a; ++i) {
    begin_a[i] = begin_c[i];
  }
  delete[] begin_c;
}

template <class T>
void Sort(T* begin, T* end) {
  --end;
  if (end - begin == 0) {
    return;
  }
  if (end - begin == 1) {
    if (*end < *begin) {
      Swap(*end, *begin);
    }
    return;
  }
  Sort(begin, begin + (end - begin) / 2 + 1);
  Sort(begin + (end - begin) / 2, end + 1);
  Merge(begin, begin + (end - begin) / 2, begin + (end - begin) / 2, end);
}

#endif