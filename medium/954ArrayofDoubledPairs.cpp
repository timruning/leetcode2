//
// Created by 宋峰 on 2019/4/7.
//
#include<vector>
#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool findDouble(vector<int> a) {
        if (a.size() % 2 != 0) {
            return false;
        }
        unordered_map<int,int> se;
        for (int i = 0; i < a.size(); i++) {
            if(se.find(a[i])!=se.end()){
                int num=se.find(a[i])->second;
                num-=1;
                se[a[i]]=num;
                if(num==0){
                    se.erase(se.find(a[i]));
                }
            }else if(se.find(a[i]*2)!=se.end()){
                int num=se.find(a[i]*2)->second;
                num+=1;
                se[a[i]*2]=num;
            }else{
                se.insert(pair<int,int>(a[i]*2,1));
            }
        }
        if (se.size() != 0) {
            return false;
        } else {
            return true;
        }
    }

    bool canReorderDoubled(vector<int> &A) {
        if (A.size()%2 != 0) {
            return false;
        }
        vector<int> A1;
        vector<int> A2;
        int zero_n = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < 0) {
                A1.push_back(A[i]);
            } else if (A[i] > 0) {
                A2.push_back(A[i]);
            } else {
                zero_n += 1;
            }
        }
        if (zero_n % 2 != 0) {
            return false;
        }
        sort(A1.begin(), A1.end(), greater<int>());

        for (int i = 0; i < A1.size(); i++) {
            cout << " " << A1[i];
        }
        cout << endl;
        sort(A2.begin(), A2.end());
        for (int i = 0; i < A2.size(); i++) {
            cout << " " << A2[i];
        }
        cout<<endl;


        return findDouble(A1) && findDouble(A2);
    }
};