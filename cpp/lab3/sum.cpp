#include <iostream>
#include <limits>

int sum_of_digits(int n) {
  int sum{0};
  // Модуль числа нужен что бы отрицательные числа тоже обрабатывались
  n = abs(n);
  for (; n > 0; n /= 10)
    sum += n % 10;
  return sum;
}

void ex_3() {
  int len;
  std::cout << "Set lenght of sequence: ";
  std::cin >> len;

  if (len <= 0) {
    std::cerr << "\033[31mLenght can be only positive number\033[0m\n";
    return;
  }

  // Максимально возможный int будет точно больше или равен максимально
  // возможной сумме цифр которую сможет обработать эта программа. При этом эта
  // сумма точно не будет меньше нуля, т. к. цифры не могут быть отрицательны.
  int max_sum{-1};
  int min_sum{std::numeric_limits<int>::max()};
  int max_sum_number{};
  int min_sum_number{};
  std::cout << "Enter " << len << " numbers: ";
  for (int i{0}; i < len; i++) {
    int elem;
    std::cin >> elem;
    int elem_sum{sum_of_digits(elem)};
    if (elem_sum > max_sum) {
      max_sum = elem_sum;
      max_sum_number = elem;
    }
    if (elem_sum < min_sum) {
      min_sum = elem_sum;
      min_sum_number = elem;
    }
  }

  std::cout << "Max sum is " << max_sum << " at number " << max_sum_number
            << '\n'
            << "Min sum is " << min_sum << " at number " << min_sum_number
            << '\n';
}

// Изначально я хотел сделать так но потом вспомнил что последовательность не
// обязательно сохранять ведь она не понадобится в будущем, поэтому можно
// обойтись одним циклом.
/*
void ex_3() {
  size_t len;
  std::cout << "Set lenght of sequence: ";
  std::cin >> len;

  int *seq = new int[len];
  std::cout << "Enter " << len << " numbers: ";
  for (size_t i{0}; i < len; i++)
    std::cin >> seq[i];

  int max_sum{-1};
  int min_sum{std::numeric_limits<int>::max()};
  for (size_t i{0}; i < len; i++) {
    int elem_sum{sum_of_digits(seq[i])};
    if (elem_sum > max_sum)
      max_sum = elem_sum;
    if (elem_sum < min_sum)
      min_sum = elem_sum;
  }

  std::cout << "Max sum is " << max_sum << "\nMin sum is " << min_sum << '\n';
}
*/
