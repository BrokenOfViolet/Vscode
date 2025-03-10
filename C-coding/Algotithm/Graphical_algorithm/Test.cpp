#include <iostream>
#include <vector>
using namespace std;

// 分区函数：将数组划分为两部分
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];  // 选择第一个元素作为基准
    while (low < high) {
        // 从右向左找到第一个小于基准的元素
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high];  // 将该元素移到左侧

        // 从左向右找到第一个大于基准的元素
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        arr[high] = arr[low];  // 将该元素移到右侧
    }
    arr[low] = pivot;  // 将基准元素放到正确的位置
    return low;  // 返回基准元素的位置
}

// 快速排序函数
void quicksort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // 获取分区点
        quicksort(arr, low, pi - 1);  // 递归排序左半部分
        quicksort(arr, pi + 1, high);  // 递归排序右半部分
    }
}

// 打印数组函数
void printArr(const vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 主函数
int main() {
    // 使用 initializer_list 初始化 vector
    vector<int> arr = {65, 34, 35, 87, 12, 38, 56, 46, 14, 75, 99, 23};
    quicksort(arr, 0, arr.size() - 1);  // 传递最后一个有效索引
    printArr(arr);

    return 0;
}

#include <iostream>