#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> grids;
    int numIslands(vector<vector<char>>& grid) {
        grids = grid;
        int cnt = 0;
        for( int i = 0;i < grids.size(); i++ ){
            for( int j = 0;j < grids[i].size();j ++){
                if( grids[i][j] == '1'){
                    cnt ++;
                    dfs(i,j);
                }
            }
        }
        return cnt;
    }
    void dfs(int i,int j){
        if( i>=0 && i<grids.size() && j>=0 && j<grids[0].size() && grids[i][j]=='1' ){
            grids[i][j] = '#';
            dfs(i+1,j);
            dfs(i-1,j);
            dfs(i,j+1);
            dfs(i,j-1);
        }

    }
};

int main()
{
    Solution Solution1;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << Solution1.numIslands(grid) << endl;
    return 0;
}
