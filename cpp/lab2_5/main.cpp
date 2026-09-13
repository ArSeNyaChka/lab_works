#include <iostream>


template <typename T>
int find(const T &elem, T *arr, std::size_t size) {
    for (std::size_t i = 0; i < size; ++i)
        if (arr[i] == elem)
            return i;
    return -1;
}

template <typename T>
bool contains(const T &elem, T *arr, std::size_t size) {
    if (find(elem, arr, size) == -1) return false;
    return true;
}

template <typename T>
bool change(const T &elem_1, const T &elem_2, T *arr, std::size_t size) {
    int index_1 = find(elem_1, arr, size);
    int index_2 = find(elem_2, arr, size);

    if (index_1 == -1 || index_2 == -1)
        return false;
    
    std::swap(arr[index_1], arr[index_2]);
    return true;
}

