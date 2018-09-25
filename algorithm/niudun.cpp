//
// Created by 宋峰 on 2018/9/20.
//
#include <iostream>
using namespace std;
double niutun(int n) {
    double begin = 5.;
    double squere=begin*begin;
    bool direct = true;
    if (squere > n) {
        direct = false;
    } else if (squere < n) {
        direct = true;
    } else {
        return begin;
    }
    int index=0;
    while (squere- n > 0.00001 || squere - n < -0.00001) {
        if(direct)
            begin+=(0.000005*squere/(2*begin));
        else
            begin-=(0.000005*squere/(2*begin));
        squere=begin*begin;
        if (squere > n) {
            direct = false;
        } else if (squere < n) {
            direct = true;
        } else {
            return begin;
        }
        index+=1;
        if(index>=1000000){
            cout<<index<<endl;
        }
        cout<<begin<<"\t"<<squere <<endl;
    }
    return begin;
}

double getSqrt(int n){

}