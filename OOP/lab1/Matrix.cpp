#include "Matrix.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>


std::vector<std::vector<double>> Matrix::rtnM()
{
    return this->m;
}

Matrix::Matrix() {
    this->colms = 0;
    this->rows = 0;
    m.resize(1);
    m[0].resize(1);
    m[0][0] = 0;
}
Matrix::Matrix(int rows, int colms) {
    this->colms = colms;
    this->rows = rows;
    m.resize(1);
    m[0].resize(1);
    m[0][0] = 0;
}


Matrix::Matrix(std::string str) {
    this->colms = 0;
    this->rows = 0;

    std::ifstream in(str); // окрываем файл для чтения
    if (in.is_open()) {
        in >> rows >> colms;
        m.resize(rows);
        for (int i = 0; i < rows; i++) {
            m[i].resize(colms);
            for (int j = 0; j < colms; j++) {
                in >> m[i][j];
            }
        }
    }
    else {
        std::cout << "Попробуйте ещё раз. \n";
    }
    in.close();
}

int Matrix::rtnRows()
{
    return this->rows;
}

int Matrix::rtnColms()
{
    return this->colms;
}

Matrix::Matrix(const Matrix& m1){
    colms = m1.colms;
    rows = m1.rows;
    m = m1.m;
}

Matrix& Matrix::operator=(const Matrix& m1){
    this->colms = m1.colms;
    this->rows = m1.rows;
    this->m = m1.m;
    return *this;
}

void Matrix::printMatrix() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->colms; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}

Matrix Matrix::miltOnNum(double num) {
    int colms = this->colms;
    int rows = this->rows;
    Matrix temp(colms, rows);
    temp.m.resize(temp.rows);
    for (int i = 0; i < temp.rows; i++) {
        temp.m[i].resize(temp.colms);
        for (int j = 0; j < temp.colms; j++) {
            temp.m[i][j] = m[j][i];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colms; j++) {
            temp.m[i][j] *= num;
        }
    }
    return temp;
}

Matrix Matrix::transp() {
    Matrix temp(colms, rows);

    temp.m.resize(temp.rows);
    for (int i = 0; i < temp.rows; i++) {
        temp.m[i].resize(temp.colms);
        for (int j = 0; j < temp.colms; j++) {
            temp.m[i][j] = m[j][i];
        }
    }

    return temp;
}

double Matrix::det() {

    std::vector<std::vector<double>> m = this->rtnM();
    int n = this->rtnColms();
    double num1, num2, det = 1, index, total = 1;
    double* temp{ new double[n + 1] };
    for (int i = 0; i < n; i++)
    {
        index = i;
        while (index < n && m[index][i] == 0)  index++;
        if (index == n)continue;
        if (index != i) {
            for (int j = 0; j < n; j++) {
                double temp = m[index][j];
                m[index][j] = m[i][j];
                m[i][j] = temp;
            }
            det = det * pow(-1, index - i);
        }
        for (int j = 0; j < n; j++) {
            temp[j] = m[i][j];
        }
        for (int j = i + 1; j < n; j++) {
            num1 = temp[i];
            num2 = m[j][i];
            for (int k = 0; k < n; k++) {
                m[j][k] = (num1 * m[j][k]) - (num2 * temp[k]);
            }
            total = total * num1;
        }
    }
    delete[] temp;
    for (int i = 0; i < n; i++) {
        det = det * m[i][i];
    }
    return det / total;
}

double detA(std::vector<std::vector<double>> m, int n) {

    double num1, num2, det = 1, index, total = 1;
    double* temp{ new double[n + 1] };
    for (int i = 0; i < n; i++)
    {
        index = i;
        while (index < n && m[index][i] == 0)  index++;
        if (index == n)continue;
        if (index != i) {
            for (int j = 0; j < n; j++) {
                double temp = m[index][j];
                m[index][j] = m[i][j];
                m[i][j] = temp;
            }
            det = det * pow(-1, index - i);
        }
        for (int j = 0; j < n; j++) {
            temp[j] = m[i][j];
        }
        for (int j = i + 1; j < n; j++) {
            num1 = temp[i];
            num2 = m[j][i];
            for (int k = 0; k < n; k++) {
                m[j][k]
                    = (num1 * m[j][k]) - (num2 * temp[k]);
            }
            total = total * num1;
        }
    }
    delete[] temp;
    for (int i = 0; i < n; i++) {
        det = det * m[i][i];
    }
    return (det / total);
}

Matrix Matrix::inverse() {
    int sizeM = this->colms;
    int size = this->colms - 1;
    std::vector<std::vector<double>> m = this->m;
    int detM = detA(m, sizeM);
    std::vector<std::vector<double>> temp;
    std::vector<std::vector<double>> temp1;
    temp.resize(size);
    for (int i = 0; i < size; i++)
        temp[i].resize(size);
    temp1.resize(sizeM);
    for (int i = 0; i < sizeM; i++)
        temp1[i].resize(sizeM);

    for (int q = 0; q < sizeM; q++) {
        for (int w = 0; w < sizeM; w++) {
            int ii = 0;
            int jj = 0;
            for (int i = 0; i < sizeM; i++) {
                if (i == q) continue;
                for (int j = 0; j < sizeM; j++) {
                    if (j == w) continue;

                    temp[ii][jj] = m[i][j];

                    jj++;
                }
                jj = 0;
                ii++;
            }
            temp1[q][w] = detA(temp, size) / detM * pow(-1, q + w + 2);
        }
    }
    for (int i = 0; i < sizeM; i++) {
        for (int j = 0; j < sizeM; j++) {
            std::cout << temp1[i][j] << " ";
        }
        std::cout << "\n";
    }
    Matrix fin(sizeM, sizeM);
    fin.m.resize(fin.rows);
    for (int i = 0; i < fin.rows; i++) {
        fin.m[i].resize(fin.colms);
        for (int j = 0; j < fin.colms; j++) {
            fin.m[i][j] = temp1[j][i];
        }
    }
    return fin;


    //std::cout << size << "\n";
}

void Matrix::outInTextFile() {
    std::string str; std::cout << "Введите название файла записи: "; std::cin >> str;
    std::ofstream out(str);

    if (out.is_open())
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colms; j++) {
                out << m[i][j] << " ";
            }
            out << "\n";
        }
    }
    out.close();
}

void Matrix::outInCSVFile() {
    std::string str; std::cout << "Введите название файла записи: "; std::cin >> str;
    std::ofstream out(str);

    if (out.is_open())
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colms; j++) {
                out << m[i][j] << ",";
            }
            out << "\n";
        }
    }
    out.close();
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        m[i].resize(colms);
        for (int j = 0; j < colms; j++) {
            m[i].clear();
        }
    }
    m.clear();
}
