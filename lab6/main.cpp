#include <fstream>
#include <ios>
#include <iostream>

// ВНИМАНИЕ!!!
// Страшная вайб код функция для заполнения файлов случайными цифрами
#include <cstdlib>
#include <ctime>
void fill_file_with_random_numbers(const std::string& filename, int count, int max_value = 100) {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Ошибка: не удалось открыть файл для записи!\n";
        return;
    }

    // Инициализация генератора случайных чисел
    std::srand(std::time(nullptr));

    for (int i = 0; i < count; i++) {
        int num = std::rand() % max_value + 1;  // случайное число от 1 до max_value
        ofs << num;
        if (i < count - 1) ofs << " ";  // пробел между числами
    }

    ofs.close();
}
void write_random_binary(const std::string& filename, int count, int max_value = 100) {
    std::ofstream ofs(filename, std::ios::binary);
    // std::srand(std::time(nullptr));
    for (int i = 0; i < count; i++) {
        int n = std::rand() % max_value + 1;
        std::cout << n << " ";
        ofs.write(reinterpret_cast<char*>(&n), sizeof(n));
    }
    std::cout << '\n';
    ofs.close();
}

void ex_1() {
    int n, m;
    do {
        std::cout << "Enter n and m (n>=m): ";
    std::cin >> n >> m;
    } while (n<m);
    std::fstream fs("file.txt", std::ios::out | std::ios::in);
    for (int i=1; i<=n; i++) fs << i*2 << " ";
    fs.seekg(0, std::ios::beg);
    for (int i=0; i<m; i++) {
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
        if (n%2==0) sum_n += n;
        if (n < min_n) min_n = n;
        if (n > max_n) max_n = n;
    }
    std::cout << "sum: " << sum_n << '\n';
    std::cout << "min: " << min_n << '\n';
    std::cout << "max: " << max_n << '\n';
    fs.close();
}

void ex_45() {
    std::fstream fs("random_binary_numbers", std::ios::in | std::ios::binary);
    int sum_n;
    fs.read((char*) &sum_n, sizeof(int));
    int max_n = sum_n;
    int min_n = sum_n;
    std::cout << "Enjoy! 2\n";
    int n;
    while (fs.read((char*) &n, sizeof(int))) {
        std::cout << n << "_";
        if (n%2==0) sum_n += n;
        if (n < min_n) min_n = n;
        if (n > max_n) max_n = n;
    }
    std::cout << "Enjoy! 3\n";
    std::cout << "sum: " << sum_n << '\n';
    std::cout << "min: " << min_n << '\n';
    std::cout << "max: " << max_n << '\n';
    fs.close();
}

int main() {
    fill_file_with_random_numbers("random_numbers.txt", 5);
    ex_23();
    write_random_binary("random_binary_numbers", 5);
    std::cout << "Enjoy!\n";
    ex_45();
}