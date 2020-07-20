#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>dp(nums.size()+1,0);
        for(int i = 1;i <= nums.size();i++){
            dp[i] = dp[i-1] + nums[i-1];
        }
        for( int i = 0;i < nums.size();i++ ){
            if( dp[ i ] == dp[ nums.size() ] - dp[i+1] ){
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {-1,1,0};
    cout << Solution1.pivotIndex( nums ) << endl;
    return 0;
}
