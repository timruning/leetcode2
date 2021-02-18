#include <iostream>
#include <vector>
#include "../algorithm/count-triplets-that-can-form-two-arrays-of-equal-xor1442.cpp"

using namespace std;

int main() {
    Solution solution;
    int a[] = {1,1,1,1,1};
    vector<int> vec(a, a + 5);
    int num = solution.countTriplets(vec);
    cout << num << endl;
}