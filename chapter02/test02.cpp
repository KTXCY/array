//
// Created by mynam on 2024/7/16.
//

#include "triangular_matrix.h"

int main() {
    array2 arr1 = {0};
    array2 arr2 = {0};
    int n = MAXSIZE * (MAXSIZE + 1) / 2;
    int arr3[n];
    int arr4[n];

    cout << "++++++++三角矩阵（下三角）+++++++" << endl;
    AssignArray_low(arr1, MAXSIZE);
    PrintArray(arr1, MAXSIZE);

    cout << "++++压缩后的三角矩阵（下三角）++++" << endl;
    PackArray_low(arr1, arr3, MAXSIZE);
    Print_PackArray(arr3, n);

    int i, j, c;
    cout << "请输入坐标：" << endl;
    cin >> i >> j;
    c = Find_index_low(i, j, MAXSIZE);
    cout << c << endl;
    cout << arr3[c] << endl;

    cout << "\n";

    cout << "++++++++三角矩阵（上三角）+++++++" << endl;
    AssignArray_up(arr2, MAXSIZE);
    PrintArray(arr2, MAXSIZE);

    cout << "++++压缩后的三角矩阵（上三角）++++" << endl;
    PackArray_up(arr2, arr4, MAXSIZE);
    Print_PackArray(arr4, n);

    cout << "请输入坐标：" << endl;
    cin >> i >> j;
    c = Find_index_up(i, j, MAXSIZE);
    cout << c << endl;
    cout << arr4[c] << endl;
    return 0;
}