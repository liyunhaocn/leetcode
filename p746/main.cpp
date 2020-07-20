#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp( cost.size()+1,0);
        if( cost.size() == 0 ){
            return 0;
        }else if(cost.size() == 1 ){
            return cost[0];
        }else if( cost.size() == 2 ){
            return min( cost[0], cost[1]);
        }
        cost.push_back(0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for( int i=2;i < cost.size();i++ ){
            dp[i] = cost[i] + min( dp[i-1],dp[i-2] );
        }
        return dp[cost.size()-1];
    }
};

int main()
{
    Solution Solution1;
    vector<int> cost = {0,0,0,0};
    cout << Solution1.minCostClimbingStairs(cost) << endl;
    return 0;
}
