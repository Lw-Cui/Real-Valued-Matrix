#include <CPP20Matrix.hpp>
#include <initializer_list>
using namespace std;
using namespace matrix;

CPP20Matrix matrix::operator+(const CPP20Matrix &m1, const CPP20Matrix &m2) {
    auto tmp(m1);
    for (int i = 0; i < m2.content.size(); i++) {
        for (int j = 0; j < m2.content.front().size(); j++) {
            tmp[i][j] += m2.content[i][j];
        }
    }
    return move(tmp);
}