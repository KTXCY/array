//
// Created by mynam on 2024/7/15.
//

#include "symmetric_matrix.h"

//生成随机数
int get_random_num(int min, int max) {
    random_device(rd);
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    int random_number = dis(gen);
    return random_number;
}

//生成一个随机下三角对称矩阵
bool AssignArray_low(int array[][MAX_NUM], int row) {
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j <= i; j++) {
            int a = get_random_num(1, 100);
            array[i][j] = a;
        }
    }
    return true;
}

//打印随机对称矩阵
void PrintArray(int array[][MAX_NUM], int row) {
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            cout << setw(4) << array[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

//生成一个随机上三角对称矩阵
bool AssignArray_up(int array[][MAX_NUM], int row) {
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = i; j < row; j++) {
            int a = get_random_num(1, 1000);
            array[i][j] = a;
        }
    }
    return true;
}

//对下三角矩阵进行压缩
bool PackArray_low(int array[][MAX_NUM], int *arr, int row) {
    int i = 0;
    int j = 0;
    int loc = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j <= i; j++) {
            arr[loc++] = array[i][j];
        }
    }
    return true;
}

//打印压缩后的矩阵
void Print_PackArray(int *arr, int row) {
    int i = 0;
    for (i = 0; i < row; i++) {
        cout << setw(4) << arr[i];
    }
    cout << "\n";
}

//对上三角矩阵进行压缩
bool PackArray_up(int array[][MAX_NUM], int *arr, int row) {
    int i = 0;
    int j = 0;
    int loc = 0;
    for (i = 0; i < row; i++) {
        for (j = i; j < row; j++) {
            arr[loc++] = array[i][j];
        }
    }
    return true;
}

/**
 * @brief 查找下标
 *
 * 根据给定的两个下标 i 和 j，以及行数 row，计算并返回下标对应的值。
 *
 * @param i 下标 i
 * @param j 下标 j
 * @param row 行数
 *
 * @return 返回计算得到的下标值，如果 i 或 j 大于等于行数，则返回 -1
 */
int Find_low(int i, int j, int row) {
    // 如果 i 或 j 大于等于行数，则返回 -1
    if (i >= row || j >= row) {
        return -1;
    }
    // 如果 i 小于 j，则交换 i 和 j 的值
    if (i < j) {
        int temp = i;
        i = j;
        j = temp;
    }
    // 计算 c 的值
    int c = i * (i + 1) / 2 + j;
    // 返回 c 的值
    return c;
}


/**
 * @brief 查找上标
 *
 * 根据给定的两个下标 i 和 j，以及行数 row，计算并返回对应的上标值。
 *
 * @param i 下标 i
 * @param j 下标 j
 * @param row 行数
 *
 * @return 如果 i 或 j 大于等于行数，则返回 -1；否则返回计算得到的上标值
 */
int Find_up(int i, int j, int row) {
    // 如果 i 或 j 大于等于行数
    if (i >= row || j >= row) {
        // 返回 -1
        return -1;
    }
    // 如果 i 大于 j
    if (i > j) {
        // 交换 i 和 j 的值
        int temp = i;
        i = j;
        j = temp;
    }
    // 计算上标值
    int c = (row * i) - ((i * (i + 1)) / 2) + j;
    // 返回计算得到的上标值
    return c;
}
