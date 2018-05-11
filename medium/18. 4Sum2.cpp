//
// Created by timruning on 18-5-9.
//

#include "../import_iostream.h"

class Sum4_18 {
public:
    string getTupleTOString(int a, int b) {
        int a1 = a > b ? b : a;
        int b1 = a > b ? a : b;
        stringstream astr;
        astr << a1;
        stringstream bstr;
        bstr << b1;
        return astr.str() + "#" + bstr.str();
    }

    string getTupleTOString(vector<int> vec) {
        sort(vec.begin(), vec.end());
        stringstream astr;
        string result = "";
        for (int i = 0; i < vec.size(); i++) {
            astr << vec[i];
        }
        result.append(astr.str() + "#");
        return result;
    }

    class tuple {
    public:
        int index[2];
        int number[2];

        tuple(const vector<int> &nums, int i, int j) {
            index[0] = i;
            index[1] = j;
            number[0] = nums[i];
            number[1] = nums[j];
        }
    };

    vector<vector<int>> distinctVectors(vector<vector<int>> vec) {
        vector<vector<int>> result;
        unordered_set<string> prefixSet;
        for (int i = 0; i < vec.size(); i++) {
            string prefix = getTupleTOString(vec[i]);
            if (prefixSet.find(prefix) == prefixSet.end()) {
                result.push_back(vec[i]);
                prefixSet.insert(prefix);
            }
        }
        return result;
    }

    vector<vector<int>> concatVectors(unordered_map<string, tuple> firstData, unordered_map<string, tuple> secondData) {
        vector<vector<int>> result;
        for (unordered_map<string, tuple>::iterator itor_i = firstData.begin(); itor_i != firstData.end(); itor_i++) {
            for (unordered_map<string, tuple>::iterator itor_j = secondData.begin();
                 itor_j != secondData.end(); itor_j++) {
                tuple first = itor_i->second;
                tuple second = itor_j->second;
                if (first.index[0] != second.index[0]
                    && first.index[0] != second.index[1]
                    && first.index[1] != second.index[0]
                    && first.index[1] != second.index[1]) {
                    vector<int> tmpVec;
                    tmpVec.push_back(first.number[0]);
                    tmpVec.push_back(first.number[1]);
                    tmpVec.push_back(second.number[0]);
                    tmpVec.push_back(second.number[1]);
                    result.push_back(tmpVec);
                }
            }
        }
        return result;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if (nums.size() < 4) {
            return result;
        }
        unordered_map<int, unordered_map<string, tuple>> LOG;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int tmpSum = nums[i] + nums[j];
                tuple t1 = tuple(nums, i, j);
                string tuple_str = getTupleTOString(i, j);
                unordered_map<int, unordered_map<string, tuple>>::iterator got = LOG.find(tmpSum);
                if (got == LOG.end()) {
                    unordered_map<string, tuple> tmpData;
                    tmpData.insert(make_pair(tuple_str, t1));
                    LOG.insert(make_pair(tmpSum, tmpData));
                } else {
                    got->second.insert(make_pair(tuple_str, t1));
                }
            }
        }
        unordered_set<int> sumSet;
        for (auto itor = LOG.begin(); itor != LOG.end(); itor++) {
            sumSet.insert(itor->first);
        }
        while (sumSet.size() > 0) {
            auto first = sumSet.begin();
            auto second = sumSet.find(target - *first);
            if (second == sumSet.end()) {
                sumSet.erase(first);
            } else {
                unordered_map<string, tuple> firstData = LOG.find(*first)->second;
                unordered_map<string, tuple> secondData = LOG.find(*second)->second;
                vector<vector<int>> result_i = concatVectors(firstData, secondData);
                result.insert(result.end(), result_i.begin(), result_i.end());
                if (*first == *second) {
                    sumSet.erase(first);
                } else {
                    sumSet.erase(second);
                    sumSet.erase(first);
                }
            }
        }

        return distinctVectors(result);
    }
};