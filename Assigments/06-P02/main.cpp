/*************************************************************************************/
// Author:  Pabitra Bhandari
// Title:   Singly linked list vector implementation using few operators.
// Course:  2143-OOP
// Semester:Fall 2021
//
// Description:
//         Uses a singly linked list as the backend for an STL like "vector"
//        class definition".
//
//Usage:
//       Usage:
//       - g++ *.cpp   to compile the file/code
// Files:
//       - main.cpp
//       - myvector2.hpp
//       - output.txt
/**************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "myvector2.hpp"

using namespace std;

int main()
{
    int a1[] = {1, 2, 3, 4, 5};
    int a2[] = {10, 20, 30};

    MyVector v1(a1, 5);
    MyVector v2(a2, 3);

    ofstream fout;
    fout.open("output.txt");

    cout << v1[2] << endl;
    // writes out 3

    v1[4] = 9;
    // v1 now = [1,2,3,4,9]

    cout << v1 << endl;
    // writes out [1,2,3,4,9] to console.

    fout << v1 << endl;
    // writes out [1,2,3,4,9] to your output file.

    MyVector v3 = v1 + v2;
    cout << v3 << endl;
    // writes out [11,22,33,4,9] to console.

    v3 = v1 - v2;
    cout << v3 << endl;
    // writes out [-9,-18,-27,4,9] to console.

    v3 = v2 - v1;
    cout << v3 << endl;
    // writes out [9,18,27,4,9] to console.

    v3 = v2 * v1;
    cout << v3 << endl;
    // writes out [10,40,90,4,9] to console.

    v3 = v1 * v2;
    cout << v3 << endl;
    // writes out [10,40,90,4,9] to console.

    v3 = v1 / v2;
    cout << v3 << endl;
    // writes out [0,0,0,4,9] to console.

    v3 = v2 / v1;
    cout << v3 << endl;
    // writes out [10,10,10,4,9] to console.

    cout << (v2 == v1) << endl;
    // writes 0 to console (false) .

    MyVector v4 = v1;
    cout << (v4 == v1) << endl;
    // writes 1 to console (true) .
}

