//
// Created by timruning on 18-8-28.
//

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    Interval merge2(Interval a, Interval b) {
        Interval result;
        result.start = a.start;
        result.end = a.end > b.end ? a.end : b.end;
        return result;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> result;
        if (intervals.size() == 0) {
            return result;
        }
        int begin = 0;
        Interval beginI = intervals[begin];
        for (int i = 1; i < intervals.size(); i++) {
            Interval endI=intervals[i];
            if(beginI.end>=endI.start){
                beginI=merge2(beginI,endI);
            }else{
                result.push_back(beginI);
                beginI=endI;
            }
        }
        result.push_back(beginI);
        return result;
    }
};