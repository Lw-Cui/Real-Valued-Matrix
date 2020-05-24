#ifndef ETMATRIX_HPP
#define ETMATRIX_HPP
#include <CPP20Matrix.hpp>

namespace matrix {

template <typename E>
class Expr {
   public:
    auto operator[](int idx) {
        return static_cast<const E &>(*this)[idx];
    }
    size_t size() {
        return static_cast<const E &>(*this).size();
    }
};

class ETVector : public Expr<ETVector> {
    const std::vector<float> content;

   public:
    float operator[](int index) const {
        return content[index];
    }

    size_t size() const {
        return content.size();
    }

    ETVector(std::vector<float> nest) : content(nest) {
    }

    template <typename T>
    ETVector(std::initializer_list<T> nest) : content(std::begin(nest), std::end(nest)) {
    }
};

template <typename E1, typename E2>
class SumVector : public Expr<SumVector<E1, E2>> {
    const E1 &e1;
    const E2 &e2;

   public:
    SumVector(const E1 &_e1, const E2 &_e2) : e1(_e1), e2(_e2) {}
    float operator[](int idx) const {
        return e1[idx] + e2[idx];
    }

    size_t size() {
        return e1.size();
    }
};

class ETMatrix : public Expr<ETMatrix> {
    std::vector<ETVector> content;

   public:
    const ETVector &operator[](int index) const {
        return content[index];
    }

    size_t size() const {
        return content.size();
    }

    template <typename T>
    ETMatrix(std::initializer_list<std::initializer_list<T>> nested) {
        for (auto &row : nested) {
            ETVector vec(row);
            content.push_back(std::move(vec));
        }
    }
};

template <typename E1, typename E2>
class SumMatrix : public Expr<SumMatrix<E1, E2>> {
    const E1 &e1;
    const E2 &e2;

   public:
    SumMatrix(const E1 &_e1, const E2 &_e2) : e1(_e1), e2(_e2) {}

    const ETVector operator[](int idx) const {
        auto t1 = e1[idx], t2 = e2[idx];
        std::vector<float> tmp;
        for (int i = 0; i < t1.size(); i++) {
            tmp.push_back(t1[i] + t2[i]);
        }

        return ETVector(tmp);
    }

    size_t size() const {
        return e1.size();
    }
};

template <typename E1, typename E2>
SumMatrix<E1, E2> operator+(const Expr<E1> &e1, const Expr<E2> &e2) {
    return SumMatrix<E1, E2>(*static_cast<const E1 *>(&e1), *static_cast<const E2 *>(&e2));
}

}  // namespace matrix

#endif