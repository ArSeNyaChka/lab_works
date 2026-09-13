#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>
#include <iostream>

template <typename T>
class Polynomial {
private:
    std::vector<T> data;

    void remove_insignificant_degrees() {
        for (int i = data.size() - 1; i > 0; --i) {
            if (data[i] == 0)
                data.pop_back();
            else return;
        }
    }

public:
    Polynomial<T>(T a) : data{a} {
        remove_insignificant_degrees();
    }
    Polynomial<T>(const std::vector<T> &vec) : data(vec) {
        remove_insignificant_degrees();
    }
    Polynomial<T>(std::vector<T> vec) : data(std::move(vec)) {
        remove_insignificant_degrees();
    }
    Polynomial<T>(std::initializer_list<T> list) : data(list) {
        remove_insignificant_degrees();
    }
    Polynomial<T>(const Polynomial<T> &other) : data(other.data) {
        remove_insignificant_degrees();
    }

    Polynomial<T>& operator=(const Polynomial<T> &other) {
        if (this == &other) {
            return *this;
        }

        data = other.data;

        return *this;
    }

    bool operator==(const Polynomial<T> &other) const {
        if (data.size() != other.data.size()) {
            return false;
        }

        for (int i = 0; i < data.size(); i++)
            if (data[i] != other.data[i])
                return false;
        
        return true;
    }

    bool operator!=(const Polynomial<T> &other) const {
        return !(*this == other);
    }

    Polynomial<T> operator+(const Polynomial<T> &other) const {
        if (data.size() < other.data.size())
            return other + *this;

        Polynomial<T> result(*this);

        for (int i = 0; i < other.data.size(); i++)
            result.data[i] += other.data[i];
        
        return result;
    }

    Polynomial<T> operator-() {
        Polynomial<T> result(*this);

        // for (int i = 0; i < data.size(); i++)
        for (T &elem : data) {
            elem = -elem;
        }

        return result;
    }

    Polynomial<T> operator-(const Polynomial<T> &other) const {
        return *this + (-other);
    }

    Polynomial<T> operator*(const Polynomial<T> &other) const {
        
    }

    Polynomial<T>& operator+=(const Polynomial<T> &other) {
        return *this = *this + other;
    }

    Polynomial<T>& operator-=(const Polynomial<T> &other) {
        return *this = *this - other;
    }

    Polynomial<T>& operator*=(const Polynomial<T> &other) {
        return *this = *this * other;
    }

    Polynomial<T>& operator=(const T &other) {
        data = {other};

        return *this;
    }

    bool operator==(const T &other) const {
        if (data.size() != 1) {
            return false;
        }
        
        return data[0] == other;
    }

    bool operator!=(const T &other) const {
        return !(*this == other);
    }

    Polynomial<T> operator+(const T &other) const {
        Polynomial<T> result(*this);

        result[0] += other;

        return result;
    }

    Polynomial<T> operator-(const T &other) const {
        return *this + (-other);
    }

    Polynomial<T> operator*(const T &other) const {
        Polynomial<T> result(*this);

        for (T &elem : result.data)
            elem *= other;

        return result;
    }

    Polynomial<T>& operator+=(const T &other) {
        return *this = *this + other;
    }

    Polynomial<T>& operator-=(const T &other) {
        return *this = *this - other;
    }

    Polynomial<T>& operator*=(const T &other) {
        return *this = *this * other;
    }

    const T& opreator[](int index) const {
        if (index >= data.size() || index < 0)
            return 0;
        
        return data[index];
    }

    int degree() {
        return data.size()
    }

    const T& operator()(const T& point) {
        T result = 0;

        for (int i = 0; i < data.size(); i++) {
            result += data[i] * std::pow(point, i);
        }

        return result;
    }

    friend std::ostream& operator<<(std::ostream &os, const Polynomial &p) {
        for (int i = p.data.size() - 1; i > 0) {
            os << p.data[i]; << " ";
        }

        return os;
    }

    friend std::istream& operator>>()
};

#endif