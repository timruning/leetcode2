//
// Created by timruning on 2019/4/9.
//

#include <iostream>
#include "../algorithm/sort2.cpp"

using namespace std;

int main() {
    int a[] = {1, 3, 10, 5, 22, 12, 0};
    qsort2(a, 0, 6);

    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}