//
// Created by timruning on 2020/4/18.
//

#include "../import_iostream.h"
#include <math.h>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxNumberOfFamilies2(int n, vector<vector<int>> &reservedSeats) {
        int result = 0;
        vector<int> num(n, 7);
        for (int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0] - 1;
            int k = reservedSeats[i][1] - 1;
            if (k == 1 || k == 2) {
                num[row] = num[row] & 3;
            } else if (k == 3 || k == 4) {
                num[row] = num[row] & 1;
            } else if (k == 5 || k == 6) {
                num[row] = num[row] & 4;
            } else if (k == 7 || k == 8) {
                num[row] = num[row] & 6;
            }
        }
        for (int i = 0; i < n; i++) {
            int x = 0;
            int t = num[i];
            for (int j = 0; j < 3; j++) {
                x = x + (t & 1);
                t = t >> 1;
            }
            if (num[i] & 2) {
                x = x > 1 ? x - 1 : 1;
            }
            result = result + x;
        }
        return result;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
        unordered_map<int, int> num;
        for (int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0] - 1;
            int k = reservedSeats[i][1] - 1;
            unordered_map<int, int>::iterator x = num.find(row);
            int t = 0;
            if (x != num.end()) {
                t = x->second;
            }
            if (k == 1 || k == 2) {
                num[row] = num[row] | 4;
            } else if (k == 3 || k == 4) {
                num[row] = num[row] | 6;
            } else if (k == 5 || k == 6) {
                num[row] = num[row] | 3;
            } else if (k == 7 || k == 8) {
                num[row] = num[row] | 1;
            }
        }

        int result = 2 * n;
        for (auto k : num) {
            int x = k.second;
            if(x==7){
                result-=2;
            }else if(x==0){

            }else{
                result-=1;
            }
        }

        return result;

    }

};