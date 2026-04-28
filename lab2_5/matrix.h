#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Matrix {
private:
    std::size_t rows;
    std::size_t cols;
    T* data;
public:
    Matrix(std::size_t rows, std::size_t cols) : rows(rows), cols(cols) {
        data = new T[rows * cols]();
    }
    ~Matrix() {
        delete[] data;
    }
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new T[rows * cols];
        std::copy(other.data, other.data + rows * cols, data);
    }
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            delete[] data;
            rows = other.rows;
            cols = other.cols;
            data = new T[rows * cols];
            std::copy(other.data, other.data + rows * cols, data);
        }
        return *this;
    }
    void set(std::size_t row, std::size_t col, const T& value) {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Index out of range");
        }
        data[row * cols + col] = value;
    }
    const T& get(std::size_t row, std::size_t col) const {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return data[row * cols + col];
    }
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Incompatible matrix dimensions");
        }
        Matrix result(rows, cols);
        for (std::size_t i = 0; i < rows * cols; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Incompatible matrix dimensions");
        }
        Matrix result(rows, other.cols);
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < other.cols; ++j) {
                T sum = T();
                for (std::size_t k = 0; k < cols; ++k) {
                    sum += get(i, k) * other.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }
    std::ostream& operator<<(std::ostream& os) const {
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                os << get(i, j) << " ";
            }
            os << std::endl;
        }
        return os;
    }
    std::istream& operator>>(std::istream& is) {
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                T value;
                is >> value;
                set(i, j, value);
            }
        }
        return is;
    }
};

#endif
