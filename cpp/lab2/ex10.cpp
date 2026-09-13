#include <cmath>
#include <iostream>

double ln1(double x) {
  double result{0};
  double elem{};
  int n{0};

  do {
    elem =
        std::pow(x - 1, 2 * n + 1) / ((2 * n + 1) * std::pow(x + 1, 2 * n + 1));
    result += elem;
    n++;
  } while (elem > .0000001);

  return result * 2;
}

double ln2(double x) {
  double result{0};
  double elem{};
  int n{0};

  do {
    elem = std::pow(-1, n) * std::pow(x - 1, n + 1) / (n + 1);
    result += elem;
    n++;
  } while (elem > .0000001);

  return result;
}

double ln3(double x) {
  double result{0};
  double elem{};
  int n{0};

  do {
    elem = std::pow(x - 1, n + 1) / ((n + 1) * std::pow(x + 1, n + 1));
    result += elem;
    n++;
  } while (elem > .0000001);

  return result;
}

int main() {
  std::cout << "x=1: ln1 = " << ln1(1) << ", ln2 = " << ln2(1)
            << ", ln3 = " << ln3(1) << ", std::ln = " << std::log(1) << '\n';
  std::cout << "x=1.2: ln1 = " << ln1(1.2) << ", ln2 = " << ln2(1.2)
            << ", ln3 = " << ln3(1.2) << ", std::ln = " << std::log(1.2)
            << '\n';
  std::cout << "x=1.5: ln1 = " << ln1(1.5) << ", ln2 = " << ln2(1.5)
            << ", ln3 = " << ln3(1.5) << ", std::ln = " << std::log(1.5)
            << '\n';
  std::cout << "x=1.8: ln1 = " << ln1(1.8) << ", ln2 = " << ln2(1.8)
            << ", ln3 = " << ln3(1.8) << ", std::ln = " << std::log(1.8)
            << '\n';
  std::cout << "x=2: ln1 = " << ln1(2) << ", ln2 = " << ln2(2)
            << ", ln3 = " << ln3(2) << ", std::ln = " << std::log(2) << '\n';

  return 0;
}
