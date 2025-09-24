#include <cmath>
#include <iostream>

int factorial(int n) {
  int result{1};
  for (int i{2}; i <= n; i++) {
    result *= i;
  }

  return result;
}

int main() {
  for (double x{0.1}; x <= 1; x += .1) {
    std::cout << "x = " << x;

    double S{0};
    int i{1};
    double elem{};
    do {
      elem = (2 * i + 1) * std::pow(x, 2 * i) / factorial(i);
      S += elem;
      i++;
    } while (elem >= .0001);
    std::cout << ", S = " << S << ", y = " << (1 + 2 * x * x) * pow(M_E, x * x)
              << '\n';
  }

  return 0;
}
