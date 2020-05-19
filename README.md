# Programming competency test

You must write two simple C++ classes implementing a real-valued matrix for which only the two following operations will be available:

* assignement of values with an initializer-list.
* addition of two matrices. We want to be able to write in C++ Matrix `m = a+b;` where a and b are matrices two. The challenge in this test is to write the first version of the Matrix class with expression templates and the second version with the most modern C++20 features but without expression temaplates. Then you will provide an analysis of the difference in speed between your two versions. The first class can be called ETMatrix and the second class CPP20Matrix. There is no need to have both classes compatible with each other.