#include <iostream>

// На самом деле это не сортировка, а всего лишь выталкивание сомого большого
// елемента на последнее место массива.
// Сложение и вычитание используются что бы
// не заводить новую переменную для перестоновки
void sort(int s[]) {
  if (s[0] > s[1]) {
    s[0] += s[1];
    s[1] = s[0] - s[1];
    s[0] -= s[1];
  }
  if (s[1] > s[2]) {
    s[1] += s[2];
    s[2] = s[1] - s[2];
    s[1] -= s[2];
  }
}

int main() {
  int sides[3];
  std::cout << "Enter triangle sides (int): ";
  std::cin >> sides[0] >> sides[1] >> sides[2];

  // Сортировка нужна, потому что нет горантии что стороны будут введены в
  // порядке возрастания
  sort(sides);

  if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
    std::cout << "Yes. Triangle is right\n";
  } else if (sides[0] + sides[1] > sides[2]) {
    std::cout << "No. Triangle isn't right\n";
  } else {
    std::cout << "Undefined. Triangle dosn't exist\n";
  }

  return 0;
}
