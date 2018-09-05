//
// Created by timruning on 18-8-28.
//

#include <iostream>
#include <vector>
#include "../medium/56MergeIntervals.cpp"

using namespace std;

int main() {
//    vector<Interval> a = {
//            Interval(1, 3),
//            Interval(2, 6),
//            Interval(8, 10),
//            Interval(15, 18)
//    };
    vector<Interval> a = {
            Interval(1, 4),
            Interval(4, 6)
    };
    Solution solution;
    vector<Interval> result = solution.merge(a);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].start << "\t" << result[i].end << endl;
    }
}