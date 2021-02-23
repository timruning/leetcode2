//
// Created by 宋峰 on 2021/2/23.
//

#include <vector>
#include <iostream>
#include "../medium/1552MagneticForceBetweenTwoBalls.cpp"
using namespace std;

int main(){
    vector<int> vec({975017321,74045490,415097519,76628781,843696647,709774845,493571894,23388841,184522636,794748308,746534625,248911596,490131472,321479956,335523769,748628710,226578862,959858170,810159464,85795199,898777852,163699246,289742726,945822015});
    int m=4;
    Solution sol;
    int t =sol.maxDistance(vec,m);
    cout<<t<<endl;
}