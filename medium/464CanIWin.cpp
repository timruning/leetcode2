//
// Created by 宋峰 on 2019/4/15.
//

class Solution {
public:
    int mem[1<<20]={};
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger)
            return true;
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 == desiredTotal) {
            return maxChoosableInteger%2;
        }
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;

        return dfs(maxChoosableInteger,desiredTotal,0);

    }

    bool dfs(int m,int d,int k){
        if(m<=0 || mem[k])
            return m>0 || mem[k]>0;
        for(int i=1;i<m;i++){
            if(!(k&1<<i) && !dfs(m,d,k&1<<i)){
                return mem[i]=1;
            }
        }
        return !(mem[k] = -1);
    }
};