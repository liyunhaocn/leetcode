#include <iostream>
#include <vector>
#include <limits.h>
#include <limits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        vector<int> dp1(prices.size(),0);
        vector<int> dp2(prices.size(),0);
        int ret = INT_MIN;
        int mini = prices[0];
        for(int i=1;i<prices.size();i++){
            mini = min( mini,prices[i] );
            ret = max(ret,prices[i] - mini);
            dp1[i] = ret;
        }

        ret = INT_MIN;
        int maxn = prices[prices.size()-1];
        for(int i = prices.size()-1 ; i >= 0;i --){
            maxn = max( maxn,prices[i] );
            ret = max(ret,maxn - prices[i]);
            dp2[i] = ret;
        }

        ret = INT_MIN;
        for(int i=0;i<prices.size()-1;i++){
            ret = max(ret,dp1[i] + dp2[i]);
        }
        return ret;
    }
};

int main()
{

    vector<int>aa = {7,1,5,3,6,4};
    Solution Solution1;
    cout<<Solution1.maxProfit(aa)<<endl;
    return 0;
}
