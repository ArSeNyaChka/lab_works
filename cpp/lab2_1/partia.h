#ifndef partialib
#define partialib

#include <string>
#include <vector>

struct PolitCoordinats {
  double x;
  double y;
};

struct Partia {
  std::string name;
  int participants;
  float rating;
  PolitCoordinats polit_coordinats;

  static std::vector<Partia> sort(std::vector<Partia>);
};

#endif