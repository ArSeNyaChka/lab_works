#include "ball.h"
#include "list.h"
#include <cctype>
#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <utility>

const char helpText[] = "\
h - print this text\n\
p - print list\n\
a - add element\n\
d - delete element\n\
c - clear list\n\
s - save list in file\n\
l - load list from file\n\
q - exit\n\
";

void printList(ListNode *&list);
void addElement(ListNode *&list);
void deleteElement(ListNode *&list);
void clearList(ListNode *&list);
void saveList(ListNode *&list);
void loadList(ListNode *&list);

int main() {
  ListNode *list = nullptr;

  std::cout << "(h for help)\n";

  while (true) {
    std::string command;
    std::cout << "\n:";
    std::getline(std::cin, command);

    if (command.size() != 1) {
      std::cout << "Incorrect command (h for help)\n";
      continue;
    }

    switch (command[0]) {
    case 'h':
      std::cout << helpText;
      break;
    case 'p':
      printList(list);
      break;
    case 'a':
      addElement(list);
      break;
    case 'd':
      deleteElement(list);
      break;
    case 'c':
      clearList(list);
      break;
    case 's':
      saveList(list);
      break;
    case 'l':
      loadList(list);
      break;
    case 'q':
      return 0;
    }
  }
}

// Очищает cin от лишних переносов строки и мусорных данных
void clrCin() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printBall(const Ball &ball, int index) {
  std::cout << "{ [" << index << "]" 
              << "\n    type: " << ballTypeToString(ball.type)
              << "\n    color: " << ball.color
              << "\n    brand: " << ball.brand
              << "\n    coast: " << ball.coast
              << "\n    quantity: " << ball.quantity
              << "\n},\n";
}

void printList(ListNode *&list) {
  ListNode *node = list;
  int count = 0;

  std::cout << "[\n";
  while (node != nullptr) {
    printBall(node->value, count);
    node = node->next;
    count++;
  }
  std::cout << "]\n";
}

void addElement(ListNode *&list) {
  int enteredNumber = 0;
  while (enteredNumber < 1 || enteredNumber > (int)BallType::Count) {
    std::cout << "Ball type (0 to print list of types): ";
    std::cin >> enteredNumber;
    clrCin();

    if (!std::cin) {
      std::cout << "Enter a (int) NUMBER!!!\n";
      std::cin.clear();
    clrCin();
      continue;
    }
    
    if (enteredNumber < 0 || enteredNumber > (int)BallType::Count)
    std::cout << "Enter number beetwen 0 and " << (int)BallType::Count << "!\n";
    else if (enteredNumber == 0)
      for (int i = 0; i < (int)BallType::Count; i++)
        std::cout << i+1 << ". " << ballTypeToString((BallType)i) << '\n';
  }
  BallType type = (BallType)(enteredNumber-1);

  std::string color;
  std::cout << "Ball color: ";
  std::getline(std::cin, color);

  std::string brand;
  std::cout << "Ball brand: ";
  std::getline(std::cin, brand);

  float coast;
  do {
    if (!std::cin) {
      std::cout << "Enter a (float) NUMBER!!!\n";
      std::cin.clear();
    clrCin();
    }
    std::cout << "Ball coast: ";
    std::cin >> coast;
    clrCin();
  } while (!std::cin);

  int quantity;
  do {
    if (!std::cin) {
      std::cout << "Enter a (int) NUMBER!!!\n";
      std::cin.clear();
    clrCin();
    }
    std::cout << "Quantity in package: ";
    std::cin >> quantity;
    clrCin();
  } while (!std::cin);

  addNodeEnd(list, (Ball){type, color, brand, coast, quantity});
}

void deleteElement(ListNode *&list) {
  int length = listLen(list);

  if (length == 0) {
    std::cout << "List is null\n";
    return;
  }

  int index = -2;

  while (index < -1 || index >= length) {
    std::cout << "Element index [0, " << length-1 << "] (-1 last, -2 cancel): ";
    std::cin >> index;
    clrCin();

    if (!std::cin) {
      std::cout << "Enter a (int) NUMBER!!!\n";
      std::cin.clear();
    clrCin();
      continue;
    }

    if (index == -2) return;
  }

  Ball deletedElement = index==-1 ? popEnd(list) : pop(list, index);

  std::cout << "Deleted element:\n";
  printBall(deletedElement, index);
}

void clearList(ListNode *&list) {
  std::string confirm;
  std::cout << "Are you sure you want to clear the list? (Y/n) ";
  std::getline(std::cin, confirm);
  
  if ((confirm != "" && std::tolower(confirm[0]) != 'y') || confirm.size() > 1) return;

  deleteList(list);

  std::cout << "List is cleared\n";
}

void saveList(ListNode *&list) {
  int length = listLen(list);
  if (length < 1) {
    std::cout << "List is null\n";
    return;
  }

  std::string fileName;
  std::cout << "File name: ";
  std::getline(std::cin, fileName);

  std::ofstream f(fileName, std::ios::binary);
  ListNode *node = list;

  if (!f.is_open()) {
    std::cerr << "Save error: Can not open file\n";
    return;
  }

  try {
    f.write((const char *) &length, sizeof(length));

    while (node != nullptr) {
      const Ball &ball = node->value;
      int intType = (int) ball.type;
      f.write((const char*) &intType, sizeof(intType));
      size_t strLen = ball.color.size();
      f.write((const char*) &strLen, sizeof(strLen));
      f.write(ball.color.data(), strLen);
      strLen = ball.brand.size();
      f.write((const char*) &strLen, sizeof(strLen));
      f.write(ball.brand.data(), strLen);
      f.write((const char*) &ball.coast, sizeof(ball.coast));
      f.write((const char*) &ball.quantity, sizeof(ball.quantity));

      node = node->next;
    }
    
    std::cout << "List saved!\n";
  } catch (const std::exception &e) {
    std::cerr << "Save error: " << e.what() << '\n';
  }

  f.close();
}

void loadList(ListNode *&list) {
  std::string fileName;
  std::cout << "File name: ";
  std::getline(std::cin, fileName);

  std::string confirm;
  std::cout << "Are you sure you want to load list from file? List be cleared (Y/n) ";
  std::getline(std::cin, confirm);
  
  if ((confirm != "" && std::tolower(confirm[0]) != 'y') || confirm.size() > 1) return;

  deleteList(list);
  
  int length;
  int count = 0;
  std::ifstream f(fileName, std::ios::binary);

  if (!f.is_open()) {
    std::cerr << "Load error: Can not open file\n";
    return;
  }

  try {
    f.read((char*) &length, sizeof(length));

    for (int i = 0; i < length; i++, count++) {
      Ball ball;

      int intType;
      f.read((char*) &intType, sizeof(intType));
      ball.type = (BallType) intType;

      size_t strLen;
      std::string tmp;

      f.read((char*) &strLen, sizeof(strLen));
      tmp.resize(strLen);
      f.read(tmp.data(), strLen);
      ball.color = std::move(tmp);

      f.read((char*) &strLen, sizeof(strLen));
      tmp.resize(strLen);
      f.read(tmp.data(), strLen);
      ball.brand = std::move(tmp);

      f.read((char*) &ball.coast, sizeof(ball.coast));
      f.read((char*) &ball.quantity, sizeof(ball.quantity));

      addNodeEnd(list, ball);
    }

    std::cout << "List loaded!\nLoad " << count << " elements\n";
  } catch (const std::exception &e) {
    std::cerr << "Load error: " << e.what() << '\n';
    std::cout << "Load " << count << "/" << length << " elements\n";
  }

  f.close();
}
