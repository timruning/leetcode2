//
// Created by 宋峰 on 2019/4/11.
//

#include <iostream>
#include "../medium/207CourseSchedule.cpp"
using namespace std;

int main(){
    int max=3;
    int arr[2][2]={{1,0},{2,1}};
    vector<pair<int,int>> schedule;
    for(int i=0;i<2;i++){
        schedule.push_back(pair<int,int>(arr[i][0],arr[i][1]));
    }

    Solution solution;
    if(solution.canFinish(3,schedule)){
        cout<<"hello"<<endl;
    }else{
        cout<<"bye"<<endl;
    }
}