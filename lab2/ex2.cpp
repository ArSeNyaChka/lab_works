#include <iostream>

int main() {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;

  int reverse_n{};
  for (int n_copy = n; n_copy > 0; n_copy /= 10) {
    reverse_n = reverse_n * 10 + n_copy % 10;
  }

  if (n == reverse_n) {
    std::cout << n << " is polindrom\n";
  } else {
    std::cout << n << " isn't polindrom\n";
  }

  return 0;
}
