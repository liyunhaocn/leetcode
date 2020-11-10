#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<": "<<(x) <<endl;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector< vector<int> > adj = vector<vector<int>>(n,vector<int>(0));
        vector<int> du(n,0);
        for(vector<int> one:edges){
            int a = one[0];
            int b = one[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            du[a]++;
            du[b]++;
        }

        vector<int> q;

        for(int i=0;i<n;i++){
            if(du[i]==1){
                q.push_back(i);
            }
        }

        int nn = n;
        while(!q.empty()){

            if(nn<=2){
                return q;
            }

            vector<int>qq;
            for(int j=0;j<q.size();j++){
                int top = q[j];
                du[top]--;
                for(int i : adj[top]){
                    du[i] --;
                    if(du[i]==1){
                        qq.push_back(i);
                    }
                }
                nn--;
            }
            q = qq;
        }
        return q;
    }
};


int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
