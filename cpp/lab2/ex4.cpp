#include <iostream>

// Написал эту функцию что бы не повторять код в разных реализациях циклов
void print_number(int n) {
  if (n % 5 && n % 7) {
    std::cout << n << '\n';
    return;
  }
  if (n % 5 == 0) {
    std::cout << "fuzz";
  }
  if (n % 7 == 0) {
    std::cout << "buzz";
  }

  std::cout << '\n';
}

int main() {
  std::cout << "In WHILE:\n";
  int i{1};
  while (i <= 500) {
    print_number(i);
    i++;
  }

  std::cout << "\n\nIn DO-WHILE:\n";
  int j{1};
  do {
    print_number(j);
    j++;
  } while (j <= 500);

  std::cout << "\n\nIn FOR:\n";
  for (int k{1}; k <= 500; k++) {
    print_number(k);
  }
}
