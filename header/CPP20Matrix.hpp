#ifndef CPP20MATRIX_HPP
#define CPP20MATRIX_HPP
#include <vector>
class CPP20Matrix
{
private:
    std::vector<std::vector<float>> content;

public:
    template <typename T>
    CPP20Matrix(std::initializer_list<std::initializer_list<T>>);
};

template <typename T>
CPP20Matrix::CPP20Matrix(std::initializer_list<std::initializer_list<T>> nested)
    : content(nested.size(), std::vector<float>(nested.begin()->size(), 0)) {}

#endif