#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;

    int findCircleNum(vector<vector<int>>& M) {
        if( M.size()==0 || M[0].size()==0){
            return 0;
        }
        this->visited = vector<vector<bool> >
            (M.size(),vector<bool>(M[0].size(),0));

        int cnt=0;
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[i].size();j++){
                if( visited[i][j] == false ){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        return cnt;
    }
    void dfs(int i,int j){
        if(  i >= 0 && i < visited.size() && j >= 0 && j < visited[0].size() && visited[i][j] == false ){
                visited[i][j] == true;

                dfs(i+1,j);
                dfs(i-1,j);
                dfs(i,j-1);
                dfs(i,j+1);
        }
    }

};

int main()
{
    Solution Solution1;

    vector< vector<int> > nums = {
         {1,1,0},
         {1,1,1},
         {0,1,1}};
    cout << Solution1.findCircleNum(nums) << endl;
    return 0;
}
