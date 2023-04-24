#include <iostream>
#include <algorithm>
struct Abitura {
  char name_[40];
  char surname_[40];
  int points_math_;
  int points_phys_;
  int points_rus_;
  int sum_points_;
};

bool Coll(Abitura first_point, Abitura second_point) {
  return first_point.sum_points_ > second_point.sum_points_;
}

int main() {
  uint64_t count;
  std::cin >> count;
  auto array = new Abitura[count];
  for (uint64_t i = 0; i < count; ++i) {
    Abitura abitura;
    std::cin >> abitura.surname_ >> abitura.name_;
    std::cin >> abitura.points_math_ >> abitura.points_phys_ >> abitura.points_rus_;
    abitura.sum_points_ = abitura.points_math_ + abitura.points_phys_ + abitura.points_rus_;
    array[i] = abitura;
  }
  std::stable_sort(array, array + count, Coll);
  for (uint64_t i = 0; i < count; ++i) {
    std::cout << array[i].surname_ << " " << array[i].name_ << "\n";
  }
  delete[] array;
}