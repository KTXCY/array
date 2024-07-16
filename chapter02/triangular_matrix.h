//
// Created by mynam on 2024/7/16.
//

#ifndef ARRAY_TRIANGULAR_MATRIX_H
#define ARRAY_TRIANGULAR_MATRIX_H

#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

constexpr int MAXSIZE = 5;

typedef int array1[MAXSIZE];
typedef array1 array2[MAXSIZE];

static random_device rd;
static mt19937 gen(rd());

int get_random_num(int min, int max);

//生成下三角三角矩阵
bool AssignArray_low(int array[][MAXSIZE], int size);

//打印矩阵
void PrintArray(int array[][MAXSIZE], int size);

//生成上三角三角矩阵
bool AssignArray_up(int array[][MAXSIZE], int size);

//压缩三角矩阵（下三角）
bool PackArray_low(int array[][MAXSIZE], int *arr, int size);

//压缩三角矩阵（上三角）
bool PackArray_up(int array[][MAXSIZE], int *arr, int size);

void Print_PackArray(int *arr, int size);

int Find_index_low(int x, int y, int size);

int Find_index_up(int x, int y, int size);

#endif //ARRAY_TRIANGULAR_MATRIX_H
