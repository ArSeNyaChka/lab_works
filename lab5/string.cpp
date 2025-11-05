#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

bool palindrom(std::string s) {
  // Удаляем все символы кроме букв и цифр
  s.erase(std::remove_if(s.begin(), s.end(),
                         [](unsigned char c) { return !std::isalnum(c); }),
          s.end());
  // Делаем все буквы строчными
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);

  for (size_t i = 0, j = s.length() - 1; i < j; i++, j--) {
    if (s[i] != s[j])
      return false;
  }

  return true;
}

bool is_password_valid(std::string_view sv) {
  if (sv.length() < 8 || sv.length() > 14)
    return false;

  bool has_upper = false;
  bool has_lower = false;
  bool has_digit = false;
  bool has_other = false;

  for (unsigned char c : sv) {
    if (c < 33 || c > 126)
      return false;

    if (std::isupper(c))
      has_upper = true;
    else if (std::islower(c))
      has_lower = true;
    else if (std::isdigit(c))
      has_digit = true;
    else
      has_other = true;
  }

  return has_upper + has_lower + has_digit + has_other >= 3;
}

void ex1() {
  std::cout << "Enter phrase: ";
  std::string s;
  std::getline(std::cin, s);
  std::cout << (palindrom(s) ? "Phrase is palindrom" : "Phrase isn't palindrom")
            << '\n';
}

void ex2() {
  std::string password;
  std::cout << "Enter password: ";
  std::getline(std::cin, password);

  if (is_password_valid(password))
    std::cout << "Chetkiy password ✅\n";
  else
    std::cout << "Fignya password ❌\n";
}
