#include <CPP20Matrix.hpp>
#include <ETMatrix.hpp>
#include <iostream>
using namespace std;
using namespace matrix;

int main() {
    cout << "HelloWorld!" << endl;

    CPP20Matrix m1{
        {1, 2},
        {3, 4},
        {5, 6},
    };

    CPP20Matrix m2{
        {3, 4},
        {5, 6},
        {1, 2},
    };

    auto m3 = m1 + m2 + m1;
    cout << m3[1][1] << endl;

    ETMatrix em1{
        {1, 2},
        {3, 4},
        {5, 6},
    };

    ETMatrix em2{
        {3, 4},
        {5, 6},
        {1, 2},
    };

    ETMatrix em3 = em1 + em2 + em1;
    cout << em3[1][1] << endl;

    auto em4 = em1 + em2 + em1;
    cout << em4[1][1] << endl;

    return 0;
}