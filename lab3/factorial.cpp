#include <iostream>

// Тип long long потому что функция факториала очень быстро растет
long long factorial(int n) {
  if (n == 0)
    return 1;
  if (n <= 2)
    return n;
  return factorial(n - 1) * n;
}

void ex_2() {
  int m, n;
  std::cout << "Enter range (from to): ";
  std::cin >> m >> n;

  if (m < 0) {
    std::cerr << "\033[31mFactorial can not be is negative\033[0m\n";
    return;
  }
  // Если введено нечетное число диапозон все равно будет начинаться со
  // следующего четного числа
  if (m % 2)
    m++;

  long long sum{0};
  for (; m <= n; m += 2)
    sum += factorial(m);

  std::cout << "Sum of even factorials is " << sum << '\n';
}
