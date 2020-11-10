#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size()<4){
            return ret;
        }
        sort(nums.begin(),nums.end());
        if(nums[0] > target){
            return ret;
        }
        for(int i = 0;i < nums.size();i ++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int t2 = target - nums[i];
            int j = i + 1;

        }

        return ret;
    }
};

int main()
{
    Solution Solution1;

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ret = Solution1.fourSum(nums,target) ;
    for(auto i:ret){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
