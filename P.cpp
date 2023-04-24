#ifndef MERGEFILE
#define MERGEFILE

template <class T, class V, class U>
void Merge(const T* first_begin, const T* first_end, const V* second_begin, const V* second_end, U* out) {
  int len_first = 0;
  int len_second = 0;
  int len_out = 0;
  while (len_first < first_end - first_begin and len_second < second_end - second_begin) {
    if (*(second_begin + len_second) < *(first_begin + len_first)) {
      out[len_out] = *(second_begin + len_second);
      ++len_second;
    } else {
      out[len_out] = *(first_begin + len_first);
      ++len_first;
    }
    ++len_out;
  }
  while (len_first < first_end - first_begin) {
    out[len_out] = *(first_begin + len_first);
    ++len_out;
    ++len_first;
  }
  while (len_second < second_end - second_begin) {
    out[len_out] = *(second_begin + len_second);
    ++len_out;
    ++len_second;
  }
}

#endif