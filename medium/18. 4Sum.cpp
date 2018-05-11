//
// Created by timruning on 18-5-9.
//

#include "../import_iostream.h"

class Sum4_18 {
public:
    string getVectorTOString(vector<int> nums) {
        sort(nums.begin(), nums.end());
        string result = "";
        for (int i = 0; i < nums.size(); i++) {
            stringstream ss;
            ss << nums[i];
            result.append(ss.str() + "#");
        }
        return result;
    }

    vector<vector<int>> sum(vector<int> nums, int target, int num) {
        sort(nums.begin(), nums.end());
        unordered_set<string> dupSet;


        vector<vector<int>> result;
        if (num == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == target) {
                    vector<int> tmp = {nums[i]};
                    result.push_back(tmp);
                    return result;
                }
            }
            return result;
        }

        int index = 0;
        while (index < nums.size()) {
            if (index != 0 && (nums[index] == nums[index - 1])) {
                index += 1;
                continue;
            } else {
                vector<int> tmpVec = vector<int>(nums);
                tmpVec.erase(tmpVec.begin() + index);
                vector<vector<int>> result3 = sum(tmpVec, target - nums[index], num - 1);
                for (int i = 0; i < result3.size(); i++) {
                    vector<int> tmpi = vector<int>(result3[i]);
                    tmpi.push_back(nums[index]);
                    string tmpstr = getVectorTOString(tmpi);
                    if (dupSet.find(tmpstr) == dupSet.end()) {
                        dupSet.insert(tmpstr);
                        result.push_back(tmpi);
                    }
                }
                index += 1;
            }
        }
        return result;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        return sum(nums, target, 4);
    }
};