#ifndef BIN
#define BIN
template <class T>
bool BinarySearch(const T* begin, const T* end, const T& value) {
  const T* mid;
  end = end - 1;
  while (begin < end + 1) {
    mid = begin + (end - begin) / 2;
    if (*mid < value) {
      begin = mid + 1;
    } else if (value < *mid) {
      end = mid - 1;
    } else {
      return true;
    }
  }
  return false;
}

template <class T>
const T* LowerBound(const T* begin, const T* end, const T& value) {
  const T* mid;
  while (begin < end) {
    mid = begin + (end - begin) / 2;
    if (*mid < value) {
      begin = mid + 1;
    } else {
      end = mid;
    }
  }
  return begin;
}

template <class T>
const T* UpperBound(const T* begin, const T* end, const T& value) {
  const T* mid;
  while (begin < end) {
    mid = begin + (end - begin) / 2;
    if (value < *mid) {
      end = mid;
    } else {
      begin = mid + 1;
    }
  }
  return begin;
}
#endif