#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>

// #define arr main // debaging

/* * * * * * *
 * ВАРИАНТ 9 *
 * * * * * * */

void ex1(int *, size_t);
void ex2(int *, size_t);
void ex3(int *, size_t);
std::string arr_to_string(int *, size_t);

int arr() {
  size_t n;
  std::cout << "Enter array lenght: ";
  std::cin >> n;

  int *arr = new int[n];
  std::cout << "Enter " << n << " numbers: ";
  for (size_t i{0}; i < n; i++) {
    int elem;
    std::cin >> elem;
    arr[i] = elem;
  }

  std::cout << arr_to_string(arr, n) << '\n';
  ex1(arr, n);
  ex2(arr, n);
  ex3(arr, n);

  delete[] arr;

  return 0;
}

void ex1(int *arr, size_t len) {
  int max_elem{0};
  for (size_t i{0}; i < len; i++) {
    if (std::abs(arr[i]) > max_elem)
      max_elem = std::abs(arr[i]);
  }
  std::cout << "Max array elem is " << max_elem << '\n';
}

void ex2(int *arr, size_t len) {
  bool between_positive = false;
  int sum = 0;

  for (size_t i = 0; i < len; i++) {
    // Пропускаем все числа пока не найдем первое положительное
    if (!between_positive) {
      if (arr[i] > 0)
        between_positive = true;
      continue;
    }
    // Если найдем второе положительное то завершаем цикл
    if (arr[i] > 0) {
      between_positive = false;
      break;
    }
    sum += arr[i];
  }

  if (between_positive)
    std::cout << "Second positive number don't find\n";
  else
    std::cout << "Sum between positive numbers is " << sum << '\n';
}

void ex3(int *arr, size_t len) {
  int zero_counter = 0;
  int *sorted_arr = new int[len];

  // Копируем все эелементы кроме нулей
  for (size_t i = 0, j = 0; i < len; i++) {
    if (arr[i] == 0) {
      zero_counter++;
      continue;
    }
    sorted_arr[j++] = arr[i];
  }

  // Заполняем оставшиеся нули
  for (size_t i = len - zero_counter; i < len; i++)
    sorted_arr[i] = 0;

  std::cout << "Sorted array: " << arr_to_string(sorted_arr, len) << '\n';

  delete[] sorted_arr;
}

// Перегрузить оператор вывода не получилось :(
// Потому что нет способа узнать длинну динамического массива
std::string arr_to_string(int *arr, size_t len) {
  std::string str{};
  str.append("[");
  for (size_t i{0}; i < len; i++) {
    str.append(std::to_string(arr[i]));
    str.append(i < len - 1 ? ", " : "]");
  }

  return str;
}
