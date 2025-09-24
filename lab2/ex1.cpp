#include <iostream>

int main() {
  int num1, num2;
  std::cout << "Enter two numbers (int): ";
  std::cin >> num1 >> num2;

  if (num1 > 0 && num2 % 2 == 0) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }

  return 0;
}
