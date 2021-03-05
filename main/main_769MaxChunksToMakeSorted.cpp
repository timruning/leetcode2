//
// Created by 宋峰 on 2021/3/4.
//

#include <vector>
#include <iostream>

#include "../medium/769MaxChunksToMakeSorted.cpp"

using namespace std;

int main(){
    vector<int> vec({7,6,5,1,2,3,4,8,9,10});
    Solution sol;
    int n = sol.maxChunksToSorted(vec);
    cout<<n<<endl;
}