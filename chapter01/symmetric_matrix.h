#ifndef ARRAY_SYMMETRIC_MATRIX_H
#define ARRAY_SYMMETRIC_MATRIX_H

#include <iomanip>
#include <random>
#include <iostream>

using namespace std;

constexpr int MAXSIZE = 10;

typedef int array1[MAXSIZE];
typedef array1 array2[MAXSIZE];

/* 初始化随机数生成器 */
static random_device rd;
/* 使用Mersenne Twister算法初始化随机数引擎 */
static mt19937 gen(rd());

int get_random_num(int min, int max);

bool AssignArray(int array[][MAXSIZE], int size);

void PrintArray(int array[][MAXSIZE], int size);

bool PackArray(int array[][MAXSIZE], int *arr, int size);

void Print_PackArray(int *arr, int size);

int Find_index(int x, int y, int size);

#endif //ARRAY_SYMMETRIC_MATRIX_H
