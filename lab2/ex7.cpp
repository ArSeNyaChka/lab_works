#include <iostream>

// Я удивлен что программа не крашнулась при делении на 0.
// Я думал что С++ не даст этого сделать.

void calculate_and_print(double a) {
  std::cout << (3 + a) / (a - 4) * (a - 4) << '\n';
}

int main() {
  std::cout << "In WHILE:\n";
  int i{1};
  while (i < 20) {
    calculate_and_print(i);
    i += 3;
  }

  std::cout << "\n\nIn DO-WHILE:\n";
  int j{1};
  do {
    calculate_and_print(j);
    j += 3;
  } while (j < 20);

  std::cout << "\n\nIn FOR:\n";
  for (int k{1}; k < 20; k += 3) {
    calculate_and_print(k);
  }
}
