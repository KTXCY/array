//
// Created by mynam on 2024/7/16.
//

#include "triangular_matrix.h"

int get_random_num(int min, int max) {
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

//生成下三角三角矩阵
bool AssignArray_low(int array[][MAXSIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            array[i][j] = get_random_num(1, 100);
        }
    }
    return true;
}

//打印矩阵
void PrintArray(int array[][MAXSIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(3) << array[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

//生成上三角三角矩阵
bool AssignArray_up(int array[][MAXSIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            array[i][j] = get_random_num(1, 100);
        }
    }
    return true;
}

//压缩三角矩阵（下三角）
bool PackArray_low(int array[][MAXSIZE], int *arr, int size) {
    int loc = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            arr[loc++] = array[i][j];
        }
    }
    return true;
}

//压缩三角矩阵（上三角）
bool PackArray_up(int array[][MAXSIZE], int *arr, int size) {
    int loc = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            arr[loc++] = array[i][j];
        }
    }
    return true;
}

void Print_PackArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(3) << arr[i];
    }
    cout << "\n";
}

int Find_index_low(int x, int y, int size) {
    if (x >= size || y >= size) {
        return -1;
    }
    if (x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    return x * (x + 1) / 2 + y;
}


int Find_index_up(int x, int y, int size) {
    if (x >= size || y >= size) {
        return -1;
    }
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
    return size * x - (x * (x + 1)) / 2 + y;
}