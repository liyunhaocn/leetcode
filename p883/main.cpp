#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> x(n,0);
        vector<int> y(n,0);
        int area = 0;
        for(int i = 0;i < n;i ++){
            for(int j =0;j<grid[i].size();j++){
                if( grid[i][j] > 0 ){
                    x[i] = max(x[i],grid[i][j]);
                    y[j] = max(y[j],grid[i][j]);
                    area += 1;
                }
            }
        }

        for(int i=0;i< n;i++){
            area += x[i];
            area += y[i];
        }
        return area;
    }
};

int main()
{
    Solution Solution1;
    vector< vector<int> > grid = {
        {1,2},
        {3,4}
    };
    cout << Solution1.projectionArea(grid) << endl;
    return 0;
}
