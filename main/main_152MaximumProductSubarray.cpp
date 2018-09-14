//
// Created by 宋峰 on 2018/8/27.
//

#include <iostream>
#include "../algorithm/152MaximumProductSubarray.cpp"

using namespace std;

int main() {
    int a[] = {1,0,-1,2,3,-5,-2};
    vector<int> aa(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    int x = solution.maxProduct(aa);
    cout << x << endl;
}