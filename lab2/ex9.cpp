#include <cmath>
#include <iostream>

int main() {
  double x{};
  double y{};
  std::cout << "Enter a coordinats (x y): ";
  std::cin >> x >> y;

  if (y < x / 2 + 1 && y > -x / 2 - 1 && x < std::sqrt(1 - y * y))
    std::cout << "Yes\n";
  else
    std::cout << "No\n";

  return 0;
}
