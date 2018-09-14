//
// Created by 宋峰 on 2018/9/1.
//

#include <iostream>
#include "../algorithm/54SpiralMatrix.cpp"

using namespace std;

int main() {
    int a[1][3]={
            {3,2,1}
    };
    vector<vector<int> > vec;
    for(int i=0;i<1;i++){
        vector<int> x(a[i],a[i]+3);
        vec.push_back(x);
    }
    Solution solution;
    vector<int> result = solution.spiralOrder(vec);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}