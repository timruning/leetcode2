//
// Created by timruning on 18-8-27.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int result = 0;
        unordered_map<int, int> map;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum==k){
                result+=1;
            }
            std::unordered_map<int, int>::const_iterator got = map.find(sum);
            std::unordered_map<int, int>::const_iterator got2 = map.find(sum-k);
            if(got2!=map.end()){
                result+=got2->second;
            }
            if (got == map.end()) {
                map.insert(pair<int, int>(sum, 1));
            } else {
                int num = got->second + 1;
                map.erase(got);
                map.emplace(pair<int, int>(sum, num));
            }
        }
        return result;
    }
};