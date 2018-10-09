//
// Created by 宋峰 on 2018/10/9.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0)
            return 0;
        int result=0;
        int start=timeSeries[0];
        for(int i=1;i<timeSeries.size();i++){
            int time=min(duration,timeSeries[i]-timeSeries[i-1]);
            result+=time;
        }
        return result+duration;
    }
};

int main(){
    Solution solution;
    int a[]={1,2};
    vector<int> vec(a,a+ sizeof(a)/ sizeof(int));
    int result=solution.findPoisonedDuration(vec,2);
    cout<<result<<endl;
}