#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "partia.h"

void print(const std::vector<Partia> &);

int main() {
  std::ifstream f("file.txt");
  std::vector<Partia> partias;
  for (int i = 0; i < 5; ++i) {
    std::string name;
    int participants;
    float rating;
    double x, y;
    f >> name >> participants >> rating >> x >> y;

    partias.push_back({name, participants, rating, {x, y}});
  }

  std::cout << "Before sort:\n";
  print(partias);

  partias = Partia::sort(partias);
  std::cout << "After sort:\n";
  print(partias);
}

void print(const std::vector<Partia> &partias) {
  for (int i = 0; i < partias.size(); ++i) {
    std::cout << i+1 << ") name: " << partias[i].name << "\n   participants: " << partias[i].participants << "\n   rating: " << partias[i].rating << "\n   polit_coordinats: {x:" << partias[i].polit_coordinats.x << " y:" << partias[i].polit_coordinats.y << "}\n";
  }
}
