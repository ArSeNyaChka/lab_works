#include <fstream>
#include <ios>
#include <iostream>

void fill_file_with_random_numbers(const std::string &filename, int count,
                                   int max_value = 100);
void write_random_binary(const std::string &filename, int count,
                         int max_value = 100);

void ex_1() {
  int n, m;
  do {
    std::cout << "Enter n and m (n>=m): ";
    std::cin >> n >> m;
  } while (n < m);

  std::fstream fs("file.txt", std::ios::out | std::ios::in);
  for (int i = 1; i <= n; i++)
    fs << i * 2 << " ";

  fs.seekg(0, std::ios::beg);
  for (int i = 0; i < m; i++) {
    int num;
    fs >> num;
    std::cout << num << " ";
  }

  std::cout << '\n';
  fs.close();
}

void ex_23() {
  std::fstream fs("random_numbers.txt", std::ios::in);
  int sum_n;
  fs >> sum_n;
  int max_n = sum_n;
  int min_n = sum_n;

  while (!fs.eof()) {
    int n;
    fs >> n;
    if (n % 2 == 0)
      sum_n += n;
    if (n < min_n)
      min_n = n;
    if (n > max_n)
      max_n = n;
  }

  std::cout << "sum: " << sum_n << '\n';
  std::cout << "min: " << min_n << '\n';
  std::cout << "max: " << max_n << '\n';
  fs.close();
}

void ex_45() {
  std::fstream fs("random_binary_numbers", std::ios::in | std::ios::binary);
  int sum_n;
  fs.read((char *)&sum_n, sizeof(int));
  int max_n = sum_n;
  int min_n = sum_n;
  int n;

  while (fs.read((char *)&n, sizeof(int))) {
    if (n % 2 == 0)
      sum_n += n;
    if (n < min_n)
      min_n = n;
    if (n > max_n)
      max_n = n;
  }

  std::cout << "sum: " << sum_n << '\n';
  std::cout << "min: " << min_n << '\n';
  std::cout << "max: " << max_n << '\n';
  fs.close();
}

int main() {
  std::cout << "№ 1\n";
  ex_1();

  std::cout << "\n№ 2-3\n";
  fill_file_with_random_numbers("random_numbers.txt", 10);
  ex_23();

  std::cout << "\n№ 4-5\n";
  write_random_binary("random_binary_numbers", 10);
  ex_45();
}

// ВНИМАНИЕ!!!
// Страшный вайб код для заполнения файлов случайными цифрами
#include <cstdlib>
#include <ctime>
void fill_file_with_random_numbers(const std::string &filename, int count,
                                   int max_value) {
  std::ofstream ofs(filename);
  if (!ofs) {
    std::cerr << "Ошибка: не удалось открыть файл для записи!\n";
    return;
  }

  // Инициализация генератора случайных чисел
  std::srand(std::time(nullptr));

  std::cout << "Random numbers in file:\n";
  for (int i = 0; i < count; i++) {
    int num = std::rand() % max_value + 1; // случайное число от 1 до max_value
    ofs << num;
    if (i < count - 1)
      ofs << " "; // пробел между числами
  }

  ofs.close();
}
void write_random_binary(const std::string &filename, int count,
                         int max_value) {
  std::ofstream ofs(filename, std::ios::binary);
  // std::srand(std::time(nullptr));
  std::cout << "Random numbers in binary file:\n";
  for (int i = 0; i < count; i++) {
    int n = std::rand() % max_value + 1;
    std::cout << n << " ";
    ofs.write(reinterpret_cast<char *>(&n), sizeof(n));
  }
  std::cout << '\n';
  ofs.close();
}