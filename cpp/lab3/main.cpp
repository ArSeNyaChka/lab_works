#include "lab3.h"
#include <iostream>

/*
 * Т. к. всего 4 задачи все они запускаются из одного файла
 * main [exercise number]
 */

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Please enter `main {exercise number}`\n";
    return 1;
  }

  switch (argv[1][0]) {
  case '1':
    ex_1();
    break;
  case '2':
    ex_2();
    break;
  case '3':
    ex_3();
    break;
  case '4':
    ex_4();
    break;
  default:
    std::cerr << "\033[31mExercise does not exist\033[0m\n";
    return 2;
  }

  return 0;
}
