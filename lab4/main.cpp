#include <iostream>

int vec();
int arr();

int main() {
  char command;
  std::cout << "Vector or array? (v/a): ";
  std::cin >> command;
  if (command == 'v')
    vec();
  if (command == 'a')
    arr();

  return 0;
}
