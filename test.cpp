#include <CPP20Matrix.hpp>
#include <iostream>
using namespace std;
using namespace matrix;

int main()
{
    cout << "HelloWorld!" << endl;
    CPP20Matrix matrix{
        {1, 2},
        {3, 4},
        {5, 6},
    };

    auto m(matrix);
    cout << m[2][1] << endl;
    auto m2 = m + CPP20Matrix{{1, 2}, {2, 3}};
    return 0;
}