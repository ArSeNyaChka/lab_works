#include "table.h"
#include <iostream>
#include <vector>


// template <typename T>
Table::Table(size_t rows, size_t cols) : m_table(rows, std::vector<int>(cols)) {}

// template <typename T>
const int &Table::get_value(size_t row, size_t col) {
  return m_table[row][col];
}

// template <typename T>
void Table::set_value(size_t row, size_t col, const int &value) {
  m_table[row][col] = value;
}

// template <typename T>
size_t Table::n_rows() {
  return m_table.size();
}

// template <typename T>
size_t Table::n_cols() {
  if (m_table.size() == 0) return 0;
  return m_table[0].size();
}

// template <typename T>
void Table::print() {
  for (std::vector<int> row : m_table) {
    for (int elem : row) std::cout << elem << " ";
    std::cout << '\n';
  }
}

// template <typename T>
double Table::average() {
  double s = 0;
  for (std::vector<int> row : m_table) for (int elem : row) s += elem;
  return s / (n_rows() * n_cols());
}
