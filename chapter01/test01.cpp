/*************************************************************************
        > File Name: Array.cpp
        > Author: XYC
        > Mail: kitschxcy@outlook.com
        > Created Time: 2024年07月15日 星期一 08时54分19秒
 ************************************************************************/
#include "symmetric_matrix.h"

int main() {
    array2 arr1;
    int n = MAXSIZE * (MAXSIZE + 1) / 2;
    int arr2[n];
    AssignArray(arr1, MAXSIZE);
    PrintArray(arr1, MAXSIZE);
    PackArray(arr1, arr2, MAXSIZE);
    Print_PackArray(arr2, n);
    int x;
    int y;
    cin >> x >> y;
    int c = Find_index(x, y, MAXSIZE);
    cout << c << endl;
    cout << arr2[c] << endl;
    return 0;
}
