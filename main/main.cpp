#include "../medium/LargestSumofAverages.cpp"
#include "../common/common.cpp"
#include "../medium/firstLeftIterator.cpp"
int main() {
    LargestSumofAverages largestSumofAverages;
    vector<int> a = {9, 1, 2, 3, 9};
    double x = largestSumofAverages.largestSumOfAverages(a, 3);
    cout << x << endl;
    return 0;
}