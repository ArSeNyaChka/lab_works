#include <cmath>
#include <iostream>

bool is_prime(int n) {
  if (n <= 1)
    return false;
  if (n != 2 && n % 2 == 0)
    return false;
  for (int i{3}; i <= std::sqrt(n) + 1; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

void ex_1() {
  // Считываем ввод диапазона
  int range[2];
  std::cout << "Enter range from: ";
  std::cin >> range[0];
  std::cout << "to: ";
  std::cin >> range[1];

  // Выводим все простые числа из диапазона
  std::cout << "Prime numbers in range [" << range[0] << ", " << range[1]
            << "]: ";
  for (int i{range[0]}; i <= range[1]; i++) {
    if (is_prime(i))
      std::cout << i << ", ";
  }
  std::cout << "\n";

  // Выводим все "Дружественные" числа из диапазона
  std::cout << "Friendly numbers in range [" << range[0] << ", " << range[1]
            << "]: ";
  int last_prime{0};
  for (int i{range[0]}; i <= range[1]; i++) {
    if (is_prime(i)) {
      if (i - 2 == last_prime)
        std::cout << "(" << last_prime << " " << i << "), ";
      last_prime = i;
    }
  }
  std::cout << "\n";
}
