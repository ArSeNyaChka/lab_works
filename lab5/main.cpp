#include <iostream>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * Компилируется только под 20+ стандартом * g++ -std=c++20
 * lab5/main.cpp lab5/string.cpp lab5/char.cpp lab5/vecroe.cpp -o
 * lab5/build/main *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * */

void ex1();
void ex2();
void chars();
void ex5();
void ex6();

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Please enter `main {exercise number}`\n";
    return 1;
  }

  switch (argv[1][0]) {
  case '1':
    ex1();
    break;
  case '2':
    ex2();
    break;
  case '3':
  case '4':
    chars();
    break;
  case '5':
    ex5();
    break;
  case '6':
    ex6();
    break;
  default:
    std::cerr << "\033[31m"
                 "Exercise does not exist"
                 "\033[0m\n";
    return 2;
  }

  return 0;
}
