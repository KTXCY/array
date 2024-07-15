/*************************************************************************
        > File Name: Array.cpp
        > Author: XYC
        > Mail: kitschxcy@outlook.com
        > Created Time: 2024年07月15日 星期一 08时54分19秒
 ************************************************************************/
#include "symmetric_matrix.h"

int main() {
    array2 arr1 = {0};
    array2 arr2 = {0};

    int x = MAX_NUM * (MAX_NUM + 1) / 2;
    int arr3[x];
    int arr4[x];

    cout << "+++++++压缩前的下三角对称矩阵++++++++++" << endl;
    AssignArray_low(arr1, MAX_NUM);
    PrintArray(arr1, MAX_NUM);

    cout << "+++++++压缩后的下三角对称矩阵++++++++++" << endl;
    PackArray_low(arr1, arr3, MAX_NUM);
    Print_PackArray(arr3, x);

    int i = 0;
    int j = 0;
    cin >> i;
    cin >> j;
    int c = Find_low(i, j, MAX_NUM);
    cout << c << endl;

    int b = arr3[c];
    cout << b << endl;


    cout << "\n";
    cout << "+++++++压缩前的上三角对称矩阵++++++++++" << endl;
    AssignArray_up(arr2, MAX_NUM);
    PrintArray(arr2, MAX_NUM);

    cout << "+++++++压缩后的上三角对称矩阵++++++++++" << endl;
    PackArray_up(arr2, arr4, MAX_NUM);
    Print_PackArray(arr4, x);

    cin >> i;
    cin >> j;
    c = Find_up(i, j, MAX_NUM);
    cout << c << endl;

    b = arr4[c];
    cout << b << endl;

    return 0;
}
