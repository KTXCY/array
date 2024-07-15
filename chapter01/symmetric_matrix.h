//
// Created by mynam on 2024/7/15.
//

#ifndef ARRAY_SYMMETRIC_MATRIX_H
#define ARRAY_SYMMETRIC_MATRIX_H

#include <iomanip>
#include <random>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace std;

constexpr int MAX_NUM = 5;

typedef int array1[MAX_NUM];
typedef array1 array2[MAX_NUM];

//生成随机数
int get_random_num(int min, int max);

//生成一个随机下三角对称矩阵
bool AssignArray_low(int array[][MAX_NUM], int row);

//打印随机对称矩阵
void PrintArray(int array[][MAX_NUM], int row);

//生成一个随机上三角对称矩阵
bool AssignArray_up(int array[][MAX_NUM], int row);

//对下三角矩阵进行压缩
bool PackArray_low(int array[][MAX_NUM], int *arr, int row);

//打印压缩后的矩阵
void Print_PackArray(int *arr, int row);

//对上三角矩阵进行压缩
bool PackArray_up(int array[][MAX_NUM], int *arr, int row);

int Find_low(int i, int j, int row);

int Find_up(int i, int j, int row);

#endif //ARRAY_SYMMETRIC_MATRIX_H
