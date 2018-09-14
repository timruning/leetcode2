//
// Created by 宋峰 on 2018/9/14.
//
#include <vector>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        int mem[64][3]={0};
        int index=0;
        int max=0;
        int label=0;
        while (num>0){
            int l=num%10;
            if(l>max){
                max=l;
                label=index;
            }
            mem[index][0]=l;
            mem[index][1]=max;
            mem[index][2]=label;
            index+=1;
            num/=10;
        }
        for(int i=index-1;i>0;i--){
            if(mem[i][0]<mem[i][1]){
                int tmp=mem[i][0];
                mem[i][0]=mem[i][1];
                mem[mem[i][2]][0]=tmp;
                break;
            }
        }
        int result=0;
        for(int i=index-1;i>=0;i--){
            result=10*result+mem[i][0];
        }
        return result;
    }
};