#include <boost/asio.hpp>
#include <CPP20Matrix.hpp>
#include <iostream>
using namespace std;
using namespace matrix;

int main()
{
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
    cout << m3[1][1] << endl;
    return 0;
}