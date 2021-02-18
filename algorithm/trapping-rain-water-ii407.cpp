#include <vector>

using namespace std;

class Cell{
    public:
        int h;
        pair<int,int> pos;
        Cell(int height,pair<int,int> pos){
            this->h = height;
            this->pos = pos;
        }
};

class Heap{
    public:
    vector<Cell> data;
    int size(){
        return data.size();
    }
    void add(Cell cell){
        this->data.push_back(cell);
        int begin = this->data.size()-1;

        while (begin>0)
        {
            int f =(begin-1)/2;
            if(data[begin].h < data[f].h){
                Cell tmp = data[begin];
                data[begin] = data[f];
                data[f]=tmp;
                begin = f;
            }else{
                break;
            }
        }
        
    }
    
    Cell pop(){
        Cell top = data[0];
        data[0] = data[data.size()-1];
        data[data.size()-1] = top;
        data.pop_back();
        int begin =0;
        while (begin<data.size())
        {
            int min = begin;
            int left = 2* begin+1;
            if(left< data.size() && data[min].h> data[left].h){
                min = left;
            }
            int right = 2*begin+2;
            if(right< data.size() && data[min].h> data[right].h){
                min = right;
            }
            if(min!=begin){
                Cell tmp = data[begin];
                data[begin] = data[min];
                data[min]=tmp;
                begin = min;
            }else{
                break;
            }
        }
        
        return top;
    }
};

class Solution {
public:
    vector<Cell> get_next(Cell top,vector<vector< int> >& heightMap ,vector<vector< int> > visit){
        int a = top.pos.first;
        int b= top.pos.second;
        vector<Cell> result;
        if(a-1>=0 && visit[a-1][b] == 0){
            result.push_back(Cell(heightMap[a-1][b],pair<int,int>(a-1,b)));
        }
        if(a+1<heightMap.size() && visit[a+1][b]==0){
            result.push_back(Cell(heightMap[a+1][b],pair<int,int>(a+1,b)));
        }
        if(b-1>=0 && visit[a][b-1]==0){
            result.push_back(Cell(heightMap[a][b-1],pair<int,int>(a,b-1)));
        }
        if(b+1<heightMap[0].size() && visit[a][b+1]==0){
            result.push_back(Cell(heightMap[a][b+1],pair<int,int>(a,b+1)));
        }
        return result;
    }
    int trapRainWater(vector<vector< int> >& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector< int> > visit(n,vector<int> (m,0));
        Heap heap;
        for(int i=0;i<n;i++){
            visit[i][0]=1;
            heap.add(Cell(heightMap[i][0],pair<int,int>(i,0)));
            visit[i][m-1]=1;
            heap.add(Cell(heightMap[i][m-1],pair<int,int>(i,m-1)));
        }
        for(int j=0;j<m;j++){
            visit[0][j]=1;
            heap.add(Cell(heightMap[0][j],pair<int,int>(0,j)));
            visit[n-1][j]=1;
            heap.add(Cell(heightMap[n-1][j],pair<int,int>(n-1,j)));
        }
        int result = 0;
        while (heap.size()>0)
        {
            Cell top =heap.pop();
            vector<Cell> next_list = get_next(top,heightMap,visit);
            
            if(next_list.size() == 0){
                continue;
            }
            for(auto next:next_list){
                visit[next.pos.first][next.pos.second]=1;
                if(next.h < top.h){
                    result+= (top.h-next.h);
                    next.h = top.h;
                }
                heap.add(next);
            }
            
        }
        
        return result;
    }
};