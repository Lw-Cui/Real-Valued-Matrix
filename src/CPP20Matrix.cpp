#include <CPP20Matrix.hpp>
#include <initializer_list>
using namespace std;
using namespace matrix;

CPP20Matrix matrix::operator+(const CPP20Matrix &m1, const CPP20Matrix &m2)
{
    return CPP20Matrix{{1}};
}

template <>
CPP20Matrix::CPP20Matrix(std::initializer_list<std::initializer_list<float>> nested)
{
    for (auto &row : nested)
    {
        std::vector<float> tmp(std::begin(row), std::end(row));
        content.push_back(std::move(tmp));
    }
}
