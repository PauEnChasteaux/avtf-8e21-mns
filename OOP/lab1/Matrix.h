#pragma once
#include<vector>
#include<string>

class Matrix {
    int rows;
    int colms;
    std::vector<std::vector<double>> m;
    std::vector<std::vector<double>> rtnM();
public:
    Matrix();
    Matrix(int rows, int colms);
    Matrix(std::string str);

    int rtnRows();
    int rtnColms();
    
    Matrix(const Matrix& m1);
    Matrix& operator=(const Matrix& m1);

    void printMatrix();
    Matrix miltOnNum(double num);
    Matrix transp();
    double det();

    Matrix inverse();

    void outInTextFile();
    void outInCSVFile();
    ~Matrix();
};
