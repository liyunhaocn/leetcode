#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp( nums.size()+1,0);
        dp[0] = 0;
        if(nums.size()==0){
            return 0;
        }
        dp[1] = nums[0];
        for(int i = 2;i <= nums.size();i++){
            dp[i] = max( dp[i-2] + nums[i-1],dp[i-1] );
        }
        return dp[nums.size()];
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {2,7,9,3,1};
    cout << Solution1.rob(nums) << endl;
    return 0;
}
