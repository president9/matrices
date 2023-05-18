#pragma once
#include <iostream>

// TODO: tests
template<class T>
class Matrix{

    private:
        T mat[2][2] = {{0,0},{0,0}};
        T det = 0;

    public:
        Matrix(){}; // by default make it a 0 vector, of size 

        Matrix(T x) {
            mat[0][0] = x;
            mat[0][1] = x;
            mat[1][0] = x;
            mat[1][1] = x;
        }

        Matrix(T a, T b, T c, T d) : det(a*c - b*d) {
            mat[0][0] = a;
            mat[0][1] = b;
            mat[1][0] = c;
            mat[1][1] = d;
        }

        Matrix operator+(Matrix& b) const {
            Matrix result;
            result.mat[0][0] = mat[0][0] + b.mat[0][0];
            result.mat[0][1] = mat[0][1] + b.mat[0][1];
            result.mat[1][0] = mat[1][0] + b.mat[1][0];
            result.mat[1][1] = mat[1][1] + b.mat[1][1];
            result.det = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
            return result;
        }

        Matrix operator-(Matrix& b) const {
            Matrix result;
            result.mat[0][0] = mat[0][0] - b.mat[0][0];
            result.mat[0][1] = mat[0][1] - b.mat[0][1];
        
            result.mat[1][0] = mat[1][0] - b.mat[1][0];
            result.mat[1][1] = mat[1][1] - b.mat[1][1];
            result.det = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
            return result;
        }

        Matrix operator*(Matrix& b) const { 
            Matrix result;
            result.mat[0][0] = mat[0][0] * b.mat[0][0] + mat[0][1] * b.mat[1][0];
            result.mat[0][1] = mat[0][0] * b.mat[0][1] + mat[0][1] * b.mat[1][1];
            result.mat[1][0] = mat[1][0] * b.mat[0][0] + mat[1][1] * b.mat[1][0];
            result.mat[1][1] = mat[1][0] * b.mat[0][1] + mat[1][1] * b.mat[1][1];
            result.det = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
            return result;
        }

        void operator*(T b) {  // scalar
            mat[0][0] *= b;
            mat[0][1] *= b;
            mat[1][0] *= b;

            mat[1][1] *= b;
            det = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
        }

        bool operator==(Matrix& b) const {  // scalar
            return mat[0][0] == b.mat[0][0] && 
                   mat[0][1] == b.mat[0][1] &&
                   mat[1][0] == b.mat[1][0] &&
                   mat[1][1] == b.mat[1][1];
        }

        T get(int a, int b) const { // TODO: do error checking
            return mat[a][b];
        } 

        void set(int a, int b, T c) { 
            mat[a][b] = c; 
            det = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
        }

        void transpose() { 
            std::swap(mat[0][1], mat[1][0]);
        }

        void show() { 
            std::cout << "[[" << mat[0][0] << ", " << mat[0][1] << "]]\n";
            std::cout << "[[" << mat[1][0] << ", " << mat[1][1] << "]]";
        }

};


