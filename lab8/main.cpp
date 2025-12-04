#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <istream>

// Следующая лаба по структурам переиграна
class Vector {
private:
  int *m_values;
  int m_length;

public:
  Vector() : m_values(nullptr), m_length(0) {}
  Vector(int length) : m_length(length) { m_values = new int[m_length]; }
  Vector(const Vector &vec) :m_length(vec.lenght()) {
    m_values = new int[m_length];
    for (std::size_t i = 0; i < m_length; i++)
      m_values[i] = vec[i];
  }
  // ~Vector() { if (m_values != nullptr) delete[] m_values; }

  int lenght() const { return m_length; }
  int &operator[](std::size_t index) { return m_values[index]; }

  const int &operator[](std::size_t index) const { return m_values[index]; }
};

int operator*(const Vector &a, const Vector &b) {
  int result = 0;
  for (int i = 0; i < a.lenght(); i++)
    result += a[i] * b[i];

  return result;
}

class Matrix {
private:
  Vector *m_values;
  int m_rows;
  int m_columns;

public:
  Matrix() : m_values(nullptr), m_rows(0), m_columns(0) {}
  Matrix(int rows, int colums) : m_rows(rows), m_columns(colums) {
    m_values = new Vector[m_rows];
    for (int i = 0; i < m_rows; i++)
      m_values[i] = Vector(colums);
  }
  Matrix(const Matrix &m) : m_rows(m.rows()), m_columns(m.colums()) {
    m_values = new Vector[m_rows];
    for (int i = 0; i < m_rows; i++)
      m_values[i] = m[i];
  }
  // ~Matrix() { if (m_values != nullptr) delete[] m_values; }

  Matrix transpose() const {
    Matrix mtrx = Matrix(m_columns, m_rows);
    for (int i = 0; i < m_rows; i++)
      for (int j = 0; j < m_columns; j++)
        mtrx[j][i] = m_values[i][j];
    return mtrx;
  }

  Vector getRow(std::size_t index) const { return m_values[index]; }

  Vector getColumn(std::size_t index) const { return this->transpose()[index]; }

  // Vector &at(std::size_t index) {&m_values[index];}
  Vector &operator[](std::size_t index) { return m_values[index]; }
  const Vector &operator[](std::size_t index) const { return m_values[index]; }
  int rows() const { return m_rows; }
  int colums() const { return m_columns; }
};

// Классы я делал по большей части ради этого
std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
  int rows = matrix.rows();
  int colums = matrix.colums();
  for (std::size_t i = 0; i < rows; i++) {
    os << '[';
    for (std::size_t j = 0; j < colums; j++)
      os << matrix[i][j] << (j < colums - 1 ? "\t" : "]\n");
  }
  return os;
}

std::istream &operator>>(std::istream &is, Matrix &matrix) {
  for (int i = 0; i < matrix.rows(); i++)
    for (int j = 0; j < matrix.colums(); j++)
      is >> matrix[i][j];

  return is;
}

Matrix operator+(const Matrix &A, const Matrix &B) {
  Matrix C(A.rows(), A.colums());
  for (int i = 0; i < A.rows(); i++)
    for (int j = 0; j < A.colums(); j++)
      C[i][j] = A[i][j] + B[i][j];

  return C;
}

Matrix operator*(int a, const Matrix &B) {
  Matrix C(B.rows(), B.colums());
  for (int i = 0; i < B.rows(); i++)
    for (int j = 0; j < B.colums(); j++)
      C[i][j] = B[i][j] * a;

  return C;
}

Matrix operator*(const Matrix &A, const Matrix &B) {
  Matrix C(A.rows(), B.colums());
  for (int i = 0; i < A.rows(); i++)
    for (int j = 0; j < B.colums(); j++)
      C[i][j] = A.getRow(i) * B.getColumn(j);
  return C;
}

int ex_1();
int ex_2();

int main() { int n; std::cout << "№ "; std::cin >> n; return n == 1 ? ex_1() : ex_2(); }

int ex_1() {
  // Делаем матрицу
  int n;
  std::cout << "Enter n: ";
  std::cin >> n;
  int a, b;
  std::cout << "Enter a b: ";
  std::cin >> a >> b;
  int **matrix = new int *[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n];
    for (int j = 0; j < n; j++) {
      matrix[i][j] = rand() % (b - a + 1) + a;
    }
  }

  // Выводим матрицу
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      std::cout << '\t' << matrix[i][j] << " ";
    std::cout << '\n';
  }

  // Меняем местами максимальный и минимальный элементы по условию
  int max_negative = a - 1;
  int *max_negative_ptr = nullptr;
  int min_positive = b + 1;
  int *min_positive_ptr = nullptr;
  for (int i = n - 1; i >= 0; i--)
    for (int j = n - i - 1; j < n; j++)
      if (matrix[i][j] < min_positive && matrix[i][j] > 0) {
        min_positive = matrix[i][j];
        min_positive_ptr = matrix[i] + j; // ну или
        // min_positive_ptr = &matrix[i][j];
      }
  for (int j = 0; j < n; j++)
    for (int i = 0; i < (j < n / 2. ? j : n - j - 1); i++)
      if (matrix[i][j] > max_negative && matrix[i][j] < 0) {
        max_negative = matrix[i][j];
        max_negative_ptr = matrix[i] + j; // ну или
        // max_negative_ptr = &matrix[i][j];
      }

  if (max_negative_ptr == nullptr || min_positive_ptr == nullptr) {
    std::cout << "Не нашлось элементов подходищих под условие (перезапустите "
                 "программу, что бы сгенерировалась новая матрица)\n";
    return 1;
  }
  int temp = *max_negative_ptr;
  *max_negative_ptr = *min_positive_ptr;
  *min_positive_ptr = temp;

  // Выводим матрицу
  std::cout
      << "\n<----------------------- Swaping ----------------------->\n\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      std::cout << '\t' << matrix[i][j] << " ";
    std::cout << '\n';
  }

  return 0;
}

int ex_2() {
  int n, m;
  std::cout << "Enter n, m: ";
  std::cin >> n >> m;
  Matrix A(m, m);
  Matrix B(m, 1);
  Matrix C(n, m);
  Matrix D(n, 1);
  std::ifstream ifs("matrixes.txt");
  ifs >> A >> B >> C >> D;
  std::cout << A + 2 * B * D.transpose() * C << '\n';

  return 1;
}