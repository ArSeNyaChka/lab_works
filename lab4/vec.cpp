/*
#include <algorithm>
#include <utility>
#define vec main // testing build
*/

#include <cstddef>
#include <iostream>
#include <map>
#include <ostream>
#include <vector>

// Перегрузка оператора вывода "<<", для того что бы кравиво и удобно выводить
// вектора
std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec) {
  os << '[';
  for (size_t i{0}, size{vec.size()}; i < size; i++)
    os << vec[i] << (i < size - 1 ? ", " : "]");
  return os;
}

void ex1(const std::vector<int> &);
void ex2(std::vector<int> &);
void ex3(const std::vector<int> &);
size_t find_max(const std::vector<int> &);
size_t find_min(const std::vector<int> &);

int vec() {
  size_t n;
  std::cout << "Enter vector lenght: ";
  std::cin >> n;

  std::vector<int> vec;
  std::cout << "Enter " << n << " numbers: ";
  for (int i{0}; i < n; i++) {
    int elem;
    std::cin >> elem;
    vec.push_back(elem);
  }

  std::cout << vec << '\n';
  std::cout << "------#1------\n";
  ex1(vec);
  std::cout << "------#2------\n";
  ex2(vec);
  std::cout << "------#3------\n";
  ex3(vec);

  return 0;
}

void ex1(const std::vector<int> &vec) {
  /* Читерный способ
  std::cout << "Max elem of vector: "
            << *std::max_element(vec.begin(), vec.end()) << '\n';
  std::cout << "Min elem of vector: "
            << *std::min_element(vec.begin(), vec.end()) << '\n';
  */
  int max{vec[find_max(vec)]};
  int min{vec[find_min(vec)]};
  std::cout << "Max elem of vector: " << max << '\n';
  std::cout << "Min elem of vector: " << min << '\n';
}

void ex2(std::vector<int> &vec) {
  size_t max_index{find_max(vec)};
  size_t min_index{find_min(vec)};

  vec[max_index] += vec[min_index];
  vec[min_index] = vec[max_index] - vec[min_index];
  vec[max_index] -= vec[min_index];

  std::cout << "Swap max and min:\n" << vec << '\n';
}

// Я не придумал как это сделать без мапы
void ex3(const std::vector<int> &vec) {
  std::map<int, int> num_count;

  for (size_t i{0}; i < vec.size(); i++)
    num_count[vec[i]]++;

  std::cout << "Number of different elems is " << num_count.size() << '\n';

  // for-each цикл
  for (const auto &[num, count] : num_count)
    std::cout << num << ": " << count << '\n';
}

size_t find_max(const std::vector<int> &vec) {
  int max{vec[0]};
  size_t max_index{0};
  for (size_t i{1}; i < vec.size(); i++) {
    if (vec[i] > max) {
      max = vec[i];
      max_index = i;
    }
  }

  return max_index;
}
size_t find_min(const std::vector<int> &vec) {
  int min{vec[0]};
  size_t min_index{0};
  for (size_t i{1}; i < vec.size(); i++) {
    if (vec[i] < min) {
      min = vec[i];
      min_index = i;
    }
  }

  return min_index;
}
