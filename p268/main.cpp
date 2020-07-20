#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = nums.size();
        for(int i=0;i<nums.size();i++){
            ret ^= nums[i];
            ret ^= i;
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums {9,6,4,2,3,5,7,0,1};
    cout << Solution1.missingNumber(nums) << endl;
    return 0;
}
