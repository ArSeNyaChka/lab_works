#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

constexpr size_t VECTORS_LEN = 50;

std::vector<std::string> firstNames = {
    "Alexander", "Mikhail", "Dmitry",     "Ivan",      "Sergey",  "Andrey",
    "Nikolay",   "Pavel",   "Yuri",       "Vladimir",  "Maxim",   "Artem",
    "Roman",     "Oleg",    "Denis",      "Egor",      "Anton",   "Kirill",
    "Victor",    "Stepan",  "Konstantin", "Ilya",      "Matvey",  "Timofey",
    "Gleb",      "Fedor",   "Vasiliy",    "Grigory",   "Anatoly", "Leonid",
    "Arseniy",   "Bogdan",  "Valentin",   "Stanislav", "German",  "Savely",
    "Mark",      "Platon",  "Robert",     "Eduard",    "Alexey",  "Nikita",
    "Yaroslav",  "Ruslan",  "Evgeny",     "Ignat",     "Vadim",   "Danila",
    "Miron",     "Ostap"};

std::vector<std::string> lastNames = {
    "Ivanov",    "Petrov",     "Sidorov",   "Smirnov",  "Kuznetsov", "Popov",
    "Vasiliev",  "Sokolov",    "Mikhailov", "Novikov",  "Fedorov",   "Morozov",
    "Volkov",    "Alekseev",   "Lebedev",   "Semenov",  "Egorov",    "Pavlov",
    "Kozlov",    "Stepanov",   "Nikolaev",  "Orlov",    "Andreev",   "Makarov",
    "Nikitin",   "Zakharov",   "Zaitsev",   "Soloviev", "Borisov",   "Yakovlev",
    "Grigoriev", "Romanov",    "Vorobiev",  "Sergeev",  "Kuzmin",    "Frolov",
    "Sorokin",   "Vinogradov", "Karpov",    "Bogdanov", "Belov",     "Osipov",
    "Kiselev",   "Gusev",      "Baranov",   "Filippov", "Medvedev",  "Tikhonov",
    "Polyakov",  "Komarov"};

void ex5() {
  srand(time(0));
  std::cout << "Enter chislo imen: ";
  int couint;
  std::cin >> couint;
  for (; couint > 0; couint--)
    std::cout << firstNames[rand() % VECTORS_LEN] << " "
              << lastNames[rand() % VECTORS_LEN] << '\n';
}

void ex6() {
  int numsring;
  std::cout << "Enter num of string: ";
  std::cin >> numsring;
  std::vector<std::string> strings;
  for (; numsring >= 0; numsring--) {
    std::string s;
    std::getline(std::cin, s);
    strings.push_back(s);
  }

  std::string searching_str;
  std::cout << "Enter searching substring: ";
  std::getline(std::cin, searching_str);

  for (std::string s : strings)
    if (s.starts_with(searching_str)) // Причина тряски до С++20
      std::cout << s << '\n';
}
