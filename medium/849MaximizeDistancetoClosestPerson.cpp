//
// Created by 宋峰 on 2021/3/2.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        int result = 0;
        int mi = seats.size() - 1;
        int ma = 0;
        int gap = 0;
        int begin = -1;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                mi = min(mi, i);
                ma = max(ma, i);
                if (begin == -1) {
                    begin = i;
                } else {
                    gap = max(i - begin, gap);
                    begin = i;
                }
            }
        }
        if(seats[0]==0){
            result = result > mi ? result : mi;
        }
        if(seats[seats.size()-1]==0){
            result = result > seats.size()-1 - ma ? result : seats.size()-1 - ma;
        }
        result = result > gap / 2 ? result : gap / 2;
        return result;
    }
};