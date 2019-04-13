//
// Created by timruning on 19-4-14.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string manacherAlg(string &x) {
    string a = "#";
    for (char v:x) {
        a.push_back(v);
        a.append("#");
    }
    int pos = 0;
    int maxR = 0;
    vector<int> R(a.size(), 0);
    for (int i = 0; i < a.size(); i++) {
        R[i] = maxR > i ? min(maxR - i, R[2 * pos - i]) : 0;
        while (R[i] + i < a.size() && i >= R[i] && a[i - R[i]] == a[i + R[i]]) {
            R[i] += 1;
        }
        if (R[i] + i > maxR) {
            maxR = R[i] + i;
            pos = i;
        }
    }
    int sub[] = {0, 0};
    for (int i = 0; i < a.size(); i++) {
        if (R[i] > sub[1]) {
            sub[0] = i;
            sub[1] = R[i];
        }
    }
    string sub2 = "";
    for (int i = sub[0] - sub[1] + 1; i <= sub[0] + sub[1] - 1; i++) {
        if (i % 2 == 1) {
            sub2 += a[i];
        }
    }
    return sub2;
}

int main() {
    string x = "waabwswfd";
    string result = manacherAlg(x);
    cout << result << endl;

}