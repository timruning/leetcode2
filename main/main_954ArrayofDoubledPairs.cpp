//
// Created by 宋峰 on 2019/4/7.
//
#include "../medium/954ArrayofDoubledPairs.cpp"

using namespace std;

int main() {
    Solution solution;
    int a[] = {
            1,2,1,2
    };
    vector<int> b(a, a + 4);
    bool result = solution.canReorderDoubled(b);
    if (result) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}