#include <iostream>
#include <string>

size_t str_len(const char *str) {
  size_t i = 0;
  while (str[i++] != '\0')
    ;
  return i;
}

char *caesar_cipher(const char *str, int shift) {
  size_t lenght = str_len(str);
  char *result = new char[lenght];
  for (size_t i = 0; i < lenght; i++) {
    // Если символ не буква, то оставляем его без изменений
    if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122) {
      result[i] = str[i];
      continue;
    }
    // Запоминаем заглавная буква или строчная
    char start_pos = (str[i] < 97) ? 65 : 97;
    result[i] = (str[i] - start_pos + shift) % 26 + start_pos;
  }

  return result;
}

char *caesar_cipher_decrypt(const char *str, int shift) {
  return caesar_cipher(str, -shift);
}

void chars() {
  std::string input;
  std::cout << "Enter text: ";
  std::getline(std::cin, input);
  const char *c_style_str = input.c_str();

  int shift;
  std::cout << "Enter shift: ";
  std::cin >> shift;

  std::cout << "String: " << c_style_str << '\n';
  std::cout << "Lenght = " << str_len(c_style_str) << '\n';
  std::cout << "Shift on " << shift << ": " << caesar_cipher(c_style_str, shift)
            << '\n';
}
