//
// Created by timruning on 18-8-27.
//

#include <iostream>
#include "../medium/825FriendsOfAppropriatAges.cpp"

using namespace std;

int main() {
    vector<int> num = {98,60,24,89,84,51,61,96,108,87,68,29,14,11,13,50,13,104,57,8,57,111,92,87,9,59,65,116,56,39,55,11,21,105,57,36,48,93,20,94,35,68,64,41,37,11,50,47,8,9};
    int k = 0;
    Solution solution;
    int t = solution.numFriendRequests(num);
    cout << t << endl;
}