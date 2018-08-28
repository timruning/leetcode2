//
// Created by timruning on 18-8-27.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int> &ages) {
        if (ages.size() <= 1) {
            return 0;
        }
        unordered_map<int, int> ageNum;
        for (int i = 0; i < ages.size(); i++) {
            auto got = ageNum.find(ages[i]);
            if (got == ageNum.end()) {
                ageNum.insert(pair<int, int>(ages[i], 1));
            } else {
                int num = got->second + 1;
                ageNum.erase(got);
                ageNum.insert(pair<int, int>(ages[i], num));
            }
        }
        vector<int> keys;
        for (auto iter:ageNum) {
            keys.push_back(iter.first);
        }
        sort(keys.begin(), keys.end());
        int result = 0;
        for (int i = 0; i < keys.size(); i++) {
            if (keys[i] <= keys[i] * 0.5 + 7 || keys[i] > keys[i] || (keys[i] > 100 && keys[i] < 100)) {

            } else {
                auto got = ageNum.find(keys[i]);
                if (got->second > 1) {
                    result += got->second * (got->second-1);
                }
            }
        }

        for (int i = 0; i < keys.size() - 1; i++) {
            int num0 = ageNum.find(keys[i])->second;
            int key0 = keys[i];
            for (int j = i + 1; j < keys.size(); j++) {
                int keyi = keys[j];
                int numi = ageNum.find(keyi)->second;
                if (keyi <= key0 * 0.5 + 7 || keyi > key0 || (keyi > 100 && key0 < 100)) {

                } else {
                    result += (num0 * numi);
                }
                if (key0 <= keyi * 0.5 + 7 || key0 > keyi || (key0 > 100 && keyi < 100)) {

                } else {
                    result += (num0 * numi);
                }
            }

        }
        return result;
    }
};