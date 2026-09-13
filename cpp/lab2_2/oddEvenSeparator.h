#ifndef OddEvenSeparatorLib
#define OddEvenSeparatorLib

#include <vector>


class OddEvenSeparator {
private:
  std::vector<int> m_even{};
  std::vector<int> m_odd{};

public:
  void add_number(int);
  void even();
  void odd();
};


#endif