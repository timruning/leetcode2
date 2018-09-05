//
// Created by timruning on 18-8-28.
//

#include <iostream>
#include <vector>
#include "../medium/713SubarrayProductLessThanK.cpp"

using namespace std;

int main() {
    vector<int> a = {10, 5, 2, 6, 5};
    Solution solution;
    int result = solution.numSubarrayProductLessThanK(a, 100);
    cout << result << endl;
}

