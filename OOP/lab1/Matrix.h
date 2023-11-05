#pragma once
#include<vector>
#include<string>

class Matrix {
    int rows;
    int colms;
    std::vector<std::vector<double>> m;
    //std::vector<std::vector<double>> getCofactor(const std::vector<std::vector<double>> vect, int size);
    //void getCofactor(std::vector<std::vector<double>> vect, std::vector<std::vector<double>> temp, int p, int q, int n);
    //void adjoint(std::vector<std::vector<double>> vect, std::vector<std::vector<double>> temp);
public:
    Matrix() : rows(0), colms(0), m{ 0 }
    {}
    Matrix(int rows, int colms) : rows(rows), colms(colms), m{}
    {}
    Matrix(int rows, int colms, std::vector<std::vector<double>> m) : rows(rows), colms(colms), m{}
    {}
    Matrix(std::string str);

    int rtnRows() { return rows; }
    int rtnColms() { return colms; }
    std::vector<std::vector<double>> rtnM() { return m; }

    void printMatrix();
    void miltOnNum(double num);
    Matrix transp();
    double det(/*std::vector<std::vector<double>> m, int rows*/);

    Matrix inverse();

    void outInTextFile();
    void outInCSVFile();
    ~Matrix();
};
