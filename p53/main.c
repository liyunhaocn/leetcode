#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>



class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if(nums.size() == 1){
            return nums[0];
        }
        int sum = 0;
        int ans = INT_MIN;
        int i=0;
        for(i=0;i<numsSize;i++){
            if(sum<0){
                sum = nums[i];
                //continue;
            }else{
                sum += nums[i];
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};

int main()
{
    int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n",maxSubArray(a,9));
    return 0;
}
