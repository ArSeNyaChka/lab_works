#include <iomanip>
#include <ios>
#include <iostream>

void formated_print(double x, double y) {
  if (x >= 0)
    std::cout << " ";
  std::cout << std::fixed << std::setprecision(1) << x;
  std::cout << "  | ";
  if (y > -10.0)
    std::cout << " ";
  std::cout << std::fixed << std::setprecision(2) << y << '\n';
}

int main() {
  std::cout << "---------------\n";
  std::cout << "   x  |   y\n";
  std::cout << "---------------\n";

  for (double x{-2}; x <= 2; x += 0.5) {
    double y = -2.4 * x * x + 5 * x - 3;
    formated_print(x, y);
  }

  std::cout << "---------------\n";

  return 0;
}
