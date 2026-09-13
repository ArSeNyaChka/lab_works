#include "oddEvenSeparator.h"
#include <iostream>
#include <vector>


void OddEvenSeparator::add_number(int x) {
  if (x % 2 == 0) m_even.push_back(x);
  else m_odd.push_back(x);
}

void OddEvenSeparator::even() {
  for (int n : m_even) std::cout << n << ' ';
}

void OddEvenSeparator::odd() {
  for (int n : m_odd) std::cout << n << ' ';
}
