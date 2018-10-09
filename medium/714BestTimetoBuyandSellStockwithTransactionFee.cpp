//
// Created by 宋峰 on 2018/10/9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int buyed= - prices[0];
        int selled=0;
        for(int i=0;i<prices.size();i++){
            selled=max(selled,buyed+prices[i]-fee);
            buyed=max(buyed,selled-prices[i]);
        }
        return selled;
    }
};

int main() {
    Solution solution;
    int a[] = {1,3,7,5,10,3};
    vector<int> vec(a, a + sizeof(a) / sizeof(int));
    int result = solution.maxProfit(vec, 2);
    cout << result << endl;
}