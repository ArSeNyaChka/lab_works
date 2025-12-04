#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

// TODO: Заставить Захара придумать норм слова на английском
enum class Subject {
  ProgramingLanguages,
  ComputerScince,
  Math,
  Phisics,
  Gaming,
  Gambling,
  RussiaHistory,
  AngliskiLanguage,
  Count
};

const char *subjectsCharConstans[] = {
  "ProgramingLanguages",
  "ComputerScince",
  "Math",
  "Phisics",
  "Gaming",
  "Gambling",
  "RussiaHistory",
  "AngliskiLanguage",
};

enum class Speciality {
  MatimaticMan,
  PhizicMan,
  ProgramerMan,
  SisadminMan,
  PodderjzkaMan,
  CybersecurityMan,
  BuisnesMan,
  OligarhMan,
  BaristaMan,
  ProdovecMan,
  DiliveryMan,
  CladMan,
  SvoMan,
  BomjzMan,
  BillionerMan,
  BogatieRoditeliMen,
  Count,
};

const char *specialitysCharConstans[] = {
  "MatimaticMan",
  "PhizicMan",
  "ProgramerMan",
  "SisadminMan",
  "PodderjzkaMan",
  "CybersecurityMan",
  "BuisnesMan",
  "OligarhMan",
  "BaristaMan",
  "ProdovecMan",
  "DiliveryMan",
  "CladMan",
  "SvoMan",
  "BomjzMan",
  "BillionerMan",
  "BogatieRoditeliMen",
};

std::istream &operator>>(std::istream &is, Subject &s) {
  std::string input;
  is >> input;
  for (int i = 0; i < (int)Subject::Count; i++)
    if (subjectsCharConstans[i] == input) {s = (Subject)i; return is;}

  throw std::runtime_error("net takih subjectov!\n");
}

std::istream &operator>>(std::istream &is, Speciality &s) {
  std::string input;
  is >> input;
  for (int i = 0; i < (int)Speciality::Count; i++)
    if (specialitysCharConstans[i] == input) {s = (Speciality)i; return is;}

  throw std::runtime_error("net takih subjectov!\n");
}

std::ostream &operator<<(std::ostream &os, const Subject &s) {
  os << subjectsCharConstans[(std::size_t)s];
  return os;
}

std::ostream &operator<<(std::ostream &os, const Speciality &s) {
  os << specialitysCharConstans[(std::size_t)s];
  return os;
}

struct Student {
  std::string fullName;
  int enrollmentYear;
  Speciality faculty;
  int groupNumber;
  float middleBall; // Захар сказал так правильно
  Subject favoriteSubject;
};

int main() {
  int n;
  std::cout << "Enter n: ";
  std::cin >> n;

  std::ifstream ifs("file.txt");
  Student arr[n];

  for (int i = 0; i < n; i++)
    ifs >> arr[i].fullName >> arr[i].enrollmentYear >> arr[i].faculty >>
        arr[i].groupNumber >> arr[i].middleBall >> arr[i].favoriteSubject;

  for (int i = 0; i < n; i++)
    std::cout << "{\n  fullName: " << arr[i].fullName
              << "\n  enrollmentYear: " << arr[i].enrollmentYear
              << "\n  faculty: " << arr[i].faculty
              << "\n  groupNumber: " << arr[i].groupNumber
              << "\n  middleBall: " << arr[i].middleBall
              << "\n  favoriteSubject: " << arr[i].favoriteSubject << "\n}";
  
  std::cout << "\nKakie filters primenit? (y - enrollmentYear, b - middleBall, a - all, e - exit): ";
  char comanda;
  std::cin >> comanda;
  switch (comanda) {
  case 'y':
    std::cout << "";
  }
}