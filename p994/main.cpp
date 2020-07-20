#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    struct point{
        int x;
        int y;
        point(int x,int y):x(x),y(y){}
        point():x(0),y(0){}
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int ret = 0;
        vector< point > vp;
        vector< point > vt;
        for( int i=0;i<grid.size();i++ ){
            for(int j=0;j<grid[i].size();j++){
                if( grid[i][j] == 2 ){
                    vp.push_back( point(i,j) );
                }
            }
        }

        while( !vp.empty() ){

            while(!vp.empty()){
                point ptemp = vp.back();
                if( ptemp.x+1 < grid.size() && grid[ptemp.x+1][ptemp.y] == 1 ){
                    vt.push_back( point(ptemp.x+1,ptemp.y) );
                    grid[ptemp.x+1][ptemp.y] = 2;
                }
                if( ptemp.x-1 >=0 && grid[ptemp.x-1][ptemp.y] == 1 ){
                    vt.push_back( point(ptemp.x-1,ptemp.y) );
                    grid[ptemp.x-1][ptemp.y] = 2;
                }
                if( ptemp.y+1 < grid[0].size() && grid[ptemp.x][ptemp.y+1] == 1 ){
                    vt.push_back( point(ptemp.x,ptemp.y+1) );
                    grid[ptemp.x][ptemp.y+1] = 2;
                }
                if( ptemp.y-1 >=0 && grid[ptemp.x][ptemp.y-1] == 1 ){
                    vt.push_back( point(ptemp.x,ptemp.y-1) );
                    grid[ptemp.x][ptemp.y-1] = 2;
                }
                vp.pop_back();
            }
            vp = vt;
            if( !vp.empty() ){
                ret++;
            }
            vt.clear();

        }
        for( int i=0;i<grid.size();i++ ){
            for(int j=0;j<grid[i].size();j++){
                if( grid[i][j] == 1 ){
                    return -1;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<vector<int>> grid = {
        {0}
    };

    cout << Solution1.orangesRotting(grid) << endl;
    //debug(grid[2][2])
    return 0;
}
