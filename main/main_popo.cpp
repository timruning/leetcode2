#include "../medium/popo.cpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <unordered_set>
using namespace std;

#define MAX_NUM 100
int main() {
    int boxs[]={1, 4, 2, 2, 3, 3, 2, 4, 1};
    vector<int> vec({1, 4, 2, 2, 3, 3, 2, 4, 1});

    Solution sol;
    int n = sol.removeBoxes(vec);
    cout<<n<<endl;
    return 0;
}