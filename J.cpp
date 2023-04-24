#include <iostream>
#include <cstring>

int DeleteNoChar(char* str, char* new_str) {
  int size = 0;
  uint64_t len = strlen(str);
  for (uint64_t i = 0; i < len; ++i) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      new_str[size] = str[i] - 'a' + 'A';
      ++size;
    }
    if (str[i] >= 'A' && str[i] <= 'Z') {
      new_str[size] = str[i];
      ++size;
    }
  }
  return size;
}

bool CheckerPalindrom(char* str, int size) {
  bool checker_palindrom = true;
  for (int i = 0; i < size / 2; ++i) {
    checker_palindrom = str[i] == str[size - i - 1];
    if (!checker_palindrom) {
      break;
    }
  }
  if (checker_palindrom) {
    std::cout << "YES"
              << "\n";
    for (int i = 0; i < size; ++i) {
      std::cout << str[i];
    }
    return true;
  }
  return false;
}

void PrintPolindromAdd(char* str, int size, int i) {
  std::cout << "YES"
            << "\n";
  for (int j = 0; j < i; ++j) {
    std::cout << str[j];
  }
  std::cout << str[size - i - 1];
  for (int j = i; j < size; ++j) {
    std::cout << str[j];
  }
}

void PrintPolindromRem(char* str, int size, int i) {
  std::cout << "YES"
            << "\n";
  for (int j = 0; j < i; ++j) {
    std::cout << str[j];
  }
  for (int j = i + 1; j < size; ++j) {
    std::cout << str[j];
  }
}

void PrintPolindromRep(char* str, int size, int i) {
  std::cout << "YES"
            << "\n";
  for (int j = 0; j < i; ++j) {
    std::cout << str[j];
  }
  std::cout << str[size - i - 1];
  for (int j = i + 1; j < size; ++j) {
    std::cout << str[j];
  }
}

void CheckerChange(char* str, int size) {
  bool checker_palindrom;
  for (int i = 0; i < size / 2; ++i) {
    checker_palindrom = true;
    for (int j = i + 1; j < size / 2; ++j) {
      checker_palindrom = str[j] == str[size - 1 - j];
      if (!checker_palindrom) {
        break;
      }
    }
    if (checker_palindrom) {
      PrintPolindromRep(str, size, i);
      return;
    }
    if (str[i] != str[size - i - 1]) {
      break;
    }
  }
  for (int i = 0; i < size / 2; ++i) {
    checker_palindrom = true;
    for (int j = i; j < (size + 1) / 2; ++j) {
      checker_palindrom = str[j] == str[size - 2 - j];
      if (!checker_palindrom) {
        break;
      }
    }
    if (checker_palindrom) {
      PrintPolindromAdd(str, size, i);
      return;
    }
    if (str[i] != str[size - i - 1]) {
      break;
    }
  }
  for (int i = 0; i < size / 2; ++i) {
    checker_palindrom = true;
    for (int j = i + 1; j < (size + 1) / 2; ++j) {
      checker_palindrom = str[j] == str[size - j];
      if (!checker_palindrom) {
        break;
      }
    }
    if (checker_palindrom) {
      PrintPolindromRem(str, size, i);
      return;
    }
    if (str[i] != str[size - i - 1]) {
      break;
    }
  }
  std::cout << "NO";
}

int main() {
  char in_str[1000000];
  char str[1000000];
  std::cin.getline(in_str, 1000000);
  int size = DeleteNoChar(in_str, str);
  bool check_palindrom = CheckerPalindrom(str, size);
  if (!check_palindrom) {
    CheckerChange(str, size);
  }
}