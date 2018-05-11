#include "medium/MinCostClimbingStairs.cpp"
#include "common/common.cpp"

int main() {
    MinCostClimbingStairs minCostClimbingStairs;
    vector<int> a = {6, 1, 4, 5, 3, 2};
    int x = minCostClimbingStairs.minCostClimbingStairs(a);
    printVec(a);
    cout << x << endl;
    return 0;
}