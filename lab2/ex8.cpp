#include <iostream>

// Не самый красивый пример рекурсивной функции.
// Отдельно ввел max_i и i потому что хотел красиво пронумеровать строки.

void calc(int max_i, int a = 1, int b = 1, int i = 1) {
  std::cout << "i=" << i << ": a = " << a << ", b = " << b << '\n';
  if (i == max_i)
    return;
  calc(max_i, 3 * b + 2 * a, 2 * a + b, ++i);
}

int main() {
  calc(15);

  return 0;
}
