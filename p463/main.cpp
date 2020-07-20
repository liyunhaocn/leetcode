#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<vector<int>> grid;
    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid = grid;
        for( int i=0;i<grid.size(); i++){
            for( int j=0;j<grid[0].size();j++){
                if( grid[i][j] == 1 ){
                    return findw(i,j);
                }
            }
        }
        return 0;
    }
    int findw(int x ,int y){
        if( x >= 0 && x < grid.size() && y >= 0 && y<grid[0].size() && grid[x][y] == 1 ){
            grid[x][y] = 2;
            return cntone(x,y)
            + findw(x-1 ,y)
            + findw(x+1 ,y)
            + findw(x ,y-1)
            + findw(x ,y+1);
        }else{
            return 0;
        }
    }
    int cntone(int x,int y){
        int cnt = 0;
        if(  x-1 < 0 || grid[x-1][y] == 0 ){
            cnt++;
        }
        //debug(cnt);
        if(  x+1 >= grid.size() || grid[x+1][y] == 0 ){
            cnt++;
        }
        if(  y-1 < 0 || grid[x][y-1] == 0){
            cnt++;
        }
        if(  y+1 >= grid[0].size() || grid[x][y+1] == 0){
            cnt++;
        }
        //debug(cnt)
        return cnt;
    }
};

int main()
{
    Solution Solution1;
    vector<vector<int>> grid =
    {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    cout << Solution1.islandPerimeter(grid) << endl;
    return 0;
}
