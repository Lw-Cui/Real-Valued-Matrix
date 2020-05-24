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

    CPP20Matrix m2(vector<vector<float>>{
        {3, 4},
        {5, 6},
        {1, 2},
    });

    auto m3 = m1 + m2;
    //ETMatrix em1(m1), em2(m2);
    //auto em3 = em1 + em2;
    //cout << em3[1][1] << endl;
    return 0;
}