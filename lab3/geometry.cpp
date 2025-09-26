#include <cmath>
#include <iostream>

double circle_area(double r) { return M_PI * r * r; }

double rectangle_area(double a, double b) { return a * b; }

double right_triangle_area(double a, double b) { return a * b / 2; }

void circle() {
  double r;
  std::cout << "Enter circle radius: ";
  std::cin >> r;
  std::cout << "Circle area is " << circle_area(r) << '\n';
}

void rectangle() {
  double a, b;
  std::cout << "Enter rectangle sides: ";
  std::cin >> a >> b;
  std::cout << "Rectangle area is " << rectangle_area(a, b) << '\n';
}

void right_triangle() {
  double a, b;
  std::cout << "Enter cathetuses: ";
  std::cin >> a >> b;
  std::cout << "Right triangle area is " << right_triangle_area(a, b) << '\n';
}

void ex_4() {
  char command;
  while (true) {
    std::cout << "Calculate area of circle, rectangle, right_triangle \n"
              << "[c, r, t, or 1, 2, 3] or `q` to exit: ";
    std::cin >> command;

    switch (command) {
    case 'c':
    case '1':
      circle();
      break;
    case 'r':
    case '2':
      rectangle();
      break;
    case 't':
    case '3':
      right_triangle();
      break;
    case 'q':
      goto end_while; // goto потому что другие способы выхода из цикла не столь
                      // же тривиальные и более громоздкие
    default:
      std::cerr << "\033[31mNot valid command `" << command << "`\033[0m\n";
    }
    std::cout << '\n';
  }
end_while:
  std::cout << '\n';
}
