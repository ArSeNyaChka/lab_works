#ifndef TableLib
#define TableLib

#include <cstddef>
#include <vector>


// template <typename T>
class Table {
private:
  std::vector<std::vector<int>> m_table;

public:
  Table(size_t rows, size_t cols);
  const int &get_value(size_t row, size_t col);  // прочитать значение из ячейки со строкой row, столбцом col.
  void set_value(size_t row, size_t col, const int &value);  // записать число в ячейку со строкой row, столбцом col.
  size_t n_rows();  // вернуть число строк в таблице.
  size_t n_cols();  // вернуть число столбцов в таблице.
  void print();  // вывести на экран всю таблицу.
  double average();  // вернуть среднее арифметическое всех значений таблицы.
};


#endif