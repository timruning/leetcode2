//
// Created by 宋峰 on 2021/4/15.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int>
            sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
        vector<vector<int>> vec(N, vector<int>(N, 0));
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            vec[a][b] = 1;

            vec[b][a] = 1;

            for (int j = 0; j < N; j++) {
                if (j != a && vec[b][j] != 0 && vec[a][j]==0) {
                    vec[a][j] =vec[b][j] + 1;
                    vec[j][a] = vec[a][j];
                }
                if (j != b && vec[a][j] != 0 && vec[b][j]==0) {
                    vec[b][j] =vec[a][j]+ 1;
                    vec[j][b] = vec[b][j];
                }
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j && )
            }
        }

        vector<int> result(N,0);
        for(int i=0;i<N;i++){
            int sum = 0;
            for(int j=0;j<N;j++){
                sum+= vec[i][j];
            }
            result[i]=sum;
        }
        return result;
    }
};