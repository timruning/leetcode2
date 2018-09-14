#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int index = 0;

        int row = matrix.size();
        if(row==0){
            return result;
        }
        int column = matrix[0].size();
        if (column == 0) {
            return result;
        }
        int begin[] = {0, 0};

        result.push_back(matrix[begin[0]][begin[1]]);
        bool first=true;
        while (true) {
            int label = index % 4;
            int f = (index + 1) / 4;
            bool find = false;
            if (label == 0) {
                for (int i = begin[1] + 1; i < column - f; i++) {
                    find = true;
                    result.push_back(matrix[begin[0]][i]);
                    begin[1] = i;
                }
            } else if (label == 1) {
                for (int i = begin[0] + 1; i < row - f; i++) {
                    find = true;
                    result.push_back(matrix[i][begin[1]]);
                    begin[0] = i;
                }
            } else if (label == 2) {
                for (int i = begin[1] - 1; i >= f; i--) {
                    find = true;
                    result.push_back(matrix[begin[0]][i]);
                    begin[1] = i;
                }
            } else if (label == 3) {
                for (int i = begin[0] - 1; i >= f; i--) {
                    find = true;
                    result.push_back(matrix[i][begin[1]]);
                    begin[0] = i;
                }
            }
            index += 1;
            if (find == false) {
                if(first){
                    first= false;
                } else{
                    break;
                }
            }else{
                first= false;
            }
        }
        return result;
    }
};