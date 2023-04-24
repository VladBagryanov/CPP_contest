#include <iostream>

int main() {
  uint64_t n;
  uint64_t m;
  uint64_t k;
  std::cin >> n >> m >> k;
  auto colors = new uint64_t[k];
  for (uint64_t i = 0; i < k; ++i) {
    colors[i] = (m / k) * n + (n / k) * (m % k);
  }
  uint64_t m_ost = m % k;
  uint64_t n_ost = n % k;
  if (m_ost + n_ost > 0) {
    for (uint64_t i = 0; i < m_ost + n_ost - 1; ++i) {
      uint64_t diag = std::min(std::min(i + 1, m_ost + n_ost - i - 1), std::min(m_ost, n_ost));
      colors[i % k] += diag;
    }
  }
  for (uint64_t i = 0; i < k; ++i) {
    std::cout << colors[i] << ' ';
  }
  delete[] colors;
}