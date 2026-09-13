#include <iostream>
#include <vector>

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec) {
  os << '[';
  for (size_t i{0}, size{vec.size()}; i < size; i++)
    os << vec[i] << (i < size - 1 ? ", " : "]");
  return os;
}

float triangele(const float *side, const float *height);
template <typename T> T &maximume(T &a, T &b, T &c);
template <typename T> T *maximume(T *a, T *b, T *c);
template <typename T> T &max_vector_elem(std::vector<T> &vec);
template <typename T> T &min_vector_elem(std::vector<T> &vec);

void ex_1() {
  float f;
  float *ptr = &f;
  *ptr = 100;
  float *ptr2 = ptr;
  *ptr2 = 200;
  std::cout << "ptr value: " << ptr << '\n';
  std::cout << "ptr addres: " << &ptr << '\n';
  std::cout << "ptr2 value: " << ptr2 << '\n';
  std::cout << "ptr2 addres: " << &ptr2 << '\n';
  std::cout << "f value: " << f << '\n';
  std::cout << "f addres: " << &f << '\n';
}

void ex_2() {
  float a, b;
  std::cout << "Enter the Gungen 2: ";
  std::cin >> a >> b;
  std::cout << "Area of triangl: " << triangele(&a, &b) << '\n';
}

void ex_3() {
  int a, b, c;
  std::cout << "Enter the Gungen 3: ";
  std::cin >> a >> b >> c;
  int &maxim = maximume(a, b, c);
  maxim = (a + b + c) / 3;
  std::cout << "Cheto koroche: " << a << " " << b << " " << c << '\n';
}

void ex_4() {
  int a, b, c;
  std::cout << "Enter the Gungen 3: ";
  std::cin >> a >> b >> c;
  int *maxim = maximume(&a, &b, &c);
  *maxim = (a + b + c) / 3;
  std::cout << "Cheto koroche 2 : " << a << " " << b << " " << c << '\n';
}

void ex_5() {
  // Сгенерировано используя натуральный интеллект Захара (ни один Захар не пострадал (Подтверждено службой по охране Захаров)):
  std::vector<int> vec = {97660, 3495,  349,  3875, 9284, 34957, 76590, 4743, 9764, 1566};
  std::cout << "Before swaping: " << vec << '\n';
  int &maxim = max_vector_elem(vec);
  int &mimi = min_vector_elem(vec);
  int temp = maxim;
  maxim = mimi;
  mimi = temp;
  std::cout << "After swaping: " << vec << '\n';
}

int main() {
  std::cout << "№ 1\n";
  ex_1();
  std::cout << "\n№ 2\n";
  ex_2();
  std::cout << "\n№ 3\n";
  ex_3();
  std::cout << "\n№ 4\n";
  ex_4();
  std::cout << "\n№ 5\n";
  ex_5();
}

float triangele(const float *side, const float *height) {
  return *side * *height / 2.0;
}

template <typename T> T *maximume(T *a, T *b, T *c) {
  return (*a > *((*b > *c) ? b : c)) ? a : ((*b > *c) ? b : c);
}

template <typename T> T &maximume(T &a, T &b, T &c) {
  return (a > ((b > c) ? b : c)) ? a : ((b > c) ? b : c);
}

template <typename T> T &max_vector_elem(std::vector<T> &vec) {
  size_t max = 0;
  for (size_t i = 1; i < vec.size(); i++)
    if (vec[i] > vec[max])
      max = i;

  return vec[max];
}

template <typename T> T &min_vector_elem(std::vector<T> &vec) {
  size_t min = 0;
  for (size_t i = 1; i < vec.size(); i++)
    if (vec[i] < vec[min])
      min = i;

  return vec[min];
}
