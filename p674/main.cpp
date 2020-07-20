#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ret = 1;
        int temp = 1;
        if( nums.size()==0 ){
            return 0;
        }
        for(int i=1;i<nums.size();i++){
            if( nums[i] > nums[i-1] ){
                temp++;
                ret = max(ret, temp );
            }else{
                temp = 1;
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {1,3,5,4,7};
    cout << Solution1.findLengthOfLCIS(nums) << endl;
    return 0;
}
