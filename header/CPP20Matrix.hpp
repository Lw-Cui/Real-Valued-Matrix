#ifndef CPP20MATRIX_HPP
#define CPP20MATRIX_HPP
#include <vector>

namespace matrix {
class CPP20Matrix {
   private:
    std::vector<std::vector<float>> content;

   public:
    friend CPP20Matrix operator+(const CPP20Matrix &m1, const CPP20Matrix &m2);

    template <typename T>
    CPP20Matrix(std::initializer_list<std::initializer_list<T>>);

    template <typename T>
    CPP20Matrix(const std::vector<std::vector<T>> &);

    std::vector<float> &operator[](int index) {
        return content[index];
    }

    size_t size() const {
        return content.size();
    }
};

CPP20Matrix operator+(const CPP20Matrix &m1, const CPP20Matrix &m2);

template <typename T>
CPP20Matrix::CPP20Matrix(std::initializer_list<std::initializer_list<T>> nested) {
    for (auto &row : nested) {
        std::vector<float> tmp(std::begin(row), std::end(row));
        content.push_back(std::move(tmp));
    }
}

template <typename T>
CPP20Matrix::CPP20Matrix(const std::vector<std::vector<T>> &nested) {
    for (auto &row : nested) {
        std::vector<float> tmp(std::begin(row), std::end(row));
        content.push_back(std::move(tmp));
    }
}

template <>
inline CPP20Matrix::CPP20Matrix(const std::vector<std::vector<float>> &nested) : content(nested) {}

}  // namespace matrix

#endif