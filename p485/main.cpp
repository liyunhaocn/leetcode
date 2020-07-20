#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ret = -1;
        for(int i=0;i<nums.size();i++){
            if( nums[i]==1 ){
                cnt++;
            }else{
                cnt = 0;
            }
            ret = max( ret,cnt );
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {1,1,0,1,1,1};
    cout << Solution1.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
