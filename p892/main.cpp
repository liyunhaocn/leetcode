#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        int N = grid.size();
        int ans = 0;

        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                if (grid[r][c] > 0) {
                    ans += 2;
                    for (int k = 0; k < 4; ++k) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        int nv = 0;
                        if (0 <= nr && nr < N && 0 <= nc && nc < N)
                            nv = grid[nr][nc];

                        ans += max(grid[r][c] - nv, 0);
                    }
                }

        return ans;
    }
};




int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
