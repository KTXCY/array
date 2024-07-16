
#include "symmetric_matrix.h"

/**
 * 生成一个介于指定最小值和最大值之间的随机整数。
 *
 * 该函数利用C++标准库中的随机数生成设施，通过指定的最小值和最大值，
 * 来生成一个在这个范围内的随机整数。这在需要随机选择一个值时非常有用，
 * 比如在游戏或模拟中选择一个随机的敌人或物品。
 *
 * @param min 随机数生成的下限。
 * @param max 随机数生成的上限。
 * @return 生成的随机整数，其值在[min, max]范围内。
 */
int get_random_num(int min, int max) {
    // 使用uniform_int_distribution来确保生成的随机数在指定范围内均匀分布。
    uniform_int_distribution<> dis(min, max);
    // 从预设的随机数生成器gen中生成一个在[min, max]范围内的随机整数。
    return dis(gen);
}

/**
 * 分配二维数组元素的值
 *
 * 该函数通过填充对称矩阵的方式为一个二维数组分配值。每个元素的值是介于100和1000之间的随机数。
 * 主要适用于需要初始化为对称关系的数据结构，如权重矩阵或距离矩阵。
 *
 * @param array 一个二维数组，其每一行代表一个元素，每一列也代表一个元素。
 * @param size 数组的大小，即行数和列数。
 * @return 总是返回true，表示分配操作成功。
 */
bool AssignArray(int array[][MAXSIZE], int size) {
    // 遍历数组的每一行和每一列
    for (int i = 0; i < size; i++) {
        // 在当前行i内，遍历从0到当前列i的所有列
        for (int j = 0; j <= i; j++) {
            // 生成一个介于100和1000之间的随机数，并赋值给当前元素
            array[i][j] = get_random_num(100, 1000);
            // 由于要形成对称矩阵，将当前元素的值赋给对应的对角线上的元素
            array[j][i] = array[i][j];
        }
    }
    // 分配操作成功，返回true
    return true;
}

void PrintArray(int array[][MAXSIZE], int size) {
    // 遍历数组的每一行
    for (int i = 0; i < size; i++) {
        // 遍历当前行的每一个元素
        for (int j = 0; j < size; j++) {
            // 以四个空格为间隔打印每个元素
            cout << setw(4) << array[i][j];
        }
        // 打印行尾换行符，准备打印下一行
        cout << "\n";
    }
    // 打印额外的换行符，以分隔矩阵和后续输出
    cout << "\n";
}

/**
 * 将二维数组中的元素按照特定规则打包到一维数组中。
 *
 * @param array 一个二维数组，其每一行都是升序排列的。
 * @param arr 一个一维数组，用于存储打包后的元素。
 * @param size 二维数组的行数，即打包操作涉及的元素数量。
 * @return 如果一维数组arr足够大，可以容纳所有打包后的元素，则返回true；否则返回false。
 *
 * 注意：该函数假设二维数组的每一行都是升序排列的，且一维数组arr的大小至少为size*(size+1)/2。
 * 打包的规则是：首先将每一行的第一个元素放入一维数组中，然后是第二个元素，以此类推，直到填满一维数组。
 */
bool PackArray(int array[][MAXSIZE], int *arr, int size) {
    /* 初始化一维数组的索引位置 */
    int loc = 0;

    /* 遍历二维数组的每一行 */
    for (int i = 0; i < size; i++) {
        /* 遍历当前行，包括当前行的所有元素（利用升序排列的特性） */
        for (int j = 0; j <= i; j++) {
            /* 检查一维数组是否已满，如果已满则返回false */
            if (loc >= size * (size + 1) / 2) {
                return false;
            }
            /* 将当前元素放入一维数组中，并更新索引位置 */
            arr[loc++] = array[i][j];
        }
    }
    /* 如果所有元素都成功打包，则返回true */
    return true;
}

void Print_PackArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i];
    }
    cout << "\n";
}

/**
 * 根据给定的x、y坐标和大小，计算并返回一个特定的索引值。
 * 此函数主要用于将二维坐标转换为一维索引，适用于需要将二维数组展开为一维数组的场景。
 *
 * @param x 坐标x，表示行索引。
 * @param y 坐标y，表示列索引。
 * @param size 二维数组的大小，即行数和列数。
 * @return 返回计算得到的一维索引值。如果坐标超出数组范围，则返回false。
 */
int Find_index(int x, int y, int size) {
    // 检查坐标是否超出数组范围
    if (x >= size || y >= size) {
        return false;
    }
    // 确保x大于等于y，以满足一维索引的计算公式要求
    if (x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    // 根据一维索引的计算公式，返回计算结果
    return x * (x + 1) / 2 + y;
}