#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if( nums.size()==0 ){
            return 0;
        }

        double ret = -100000000000;
        vector<int>dp(nums.size()+1,0);
        for(int i = 1;i <= nums.size();i++){
            dp[i] = nums[i-1] + dp[i-1];
        }

        for(int i = k ;i <= nums.size();i++){
            double sum  = dp[i] - dp[i-k];
            sum /= k;
            ret = max(ret,sum);
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {5};
    cout << Solution1.findMaxAverage(nums,1) << endl;
    return 0;
}
