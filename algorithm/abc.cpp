//
// Created by 宋峰 on 2021/12/1.
//
#include <vector>
#include <iostream>

using namespace std;

int split(vector<int> &arr, int begin, int end) {
    int pre = arr[begin];
    int index = end - 1;
    for (int i = begin + 1; i <= index;) {
        if (arr[i] > pre) {
            int tmp = arr[i];
            arr[i] = arr[index];
            arr[index] = tmp;
            index--;
        } else {
            i++;
        }
    }

    if (index != begin) {
        int tmp = arr[begin];
        arr[begin] = arr[index];
        arr[index] = tmp;
    }
    return index;
}

void q_sort(vector<int> &arr, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int index = split(arr, begin, end);
    q_sort(arr, begin, index);
    q_sort(arr, index + 1, end);
}


long long simple(int x, int y) {
    int result = 1;
    if (y == 1) {
        return x;
    }
    int a = simple(x, y / 2);
    int b = simple(x, y - y / 2);
    result = a * b;
    return result;
}

int main() {
    vector<int> arr = {0,12, 3, 454, 1, 2,55, 4, 4, 2, 546, 2, 44, 98, 120, 23};
    q_sort(arr, 0, arr.size());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

