#include <iostream>
#include <bits/stdc++.h>
#include "2x2.hpp"
#define newl '\n'

using namespace std;

int main(int argc, char** argv){
    Matrix<int> mat1(1);
    Matrix<int> mat2(2);
    Matrix<int> id(1,0,0,1);
    auto mat3 = mat1 * id;
    mat2*2;
    mat3 = mat1 - mat2;
    mat3.show();
    Matrix<int> threeMat(-3);
    if(mat3 == threeMat){
        cout << "\nMatrices are same" << newl;
    }
    mat3.set(0,1, 4);
    mat3.transpose();
    cout << mat3.get(1,0);
    return EXIT_SUCCESS;
}

