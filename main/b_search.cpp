//
// Created by 宋峰 on 2021/5/31.
//
#include <vector>
using namespace std;
int b_search(vector<int> vec,int a){
    if(vec.size()==0){
        return -1;
    }

    if(vec.front()>a || vec.back()<a){
        return -1;
    }
    int left = 0;
    int right = vec.size()-1;

    while (left<=right){
        int mid = (left+right)/2;
        if(vec[mid]==a){
            if(mid==right|| (mid<right && vec[mid+1]>a)){
                return mid;
            }else{
                left=mid+1;
            }
        }else if(vec[mid]<a){
            left =mid+1;
        }else{
            right = mid-1;
        }
    }
    return -1;
}