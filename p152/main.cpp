#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if( nums.size()==0 ){
            return 0;
        }
        int ret = INT_MIN;
        int max1 = 1;
        int min1 = 1;

        for( int i = 0;i < nums.size(); i++ ){
            if( nums[i] < 0 ){
                swap(max1,min1);
            }
            max1 = max( nums[i],max1*nums[i] );
            min1 = min( nums[i],min1*nums[i] );
            debug("+++++++++++++++");
            debug(max1)
            debug(min1)
            ret = max( max1,ret );
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {2,3,-2,4,0,8,-4};
    debug( Solution1.maxProduct(nums))
    return 0;
}
