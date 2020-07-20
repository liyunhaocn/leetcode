#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nums;
    bool findw(int pos,int sum){
        if( pos>= nums.size() ){
            return false;
        }else if( sum == nums[pos] ){
            return true;
        }
        return findw(pos+1,sum-nums[pos]) || findw(pos+1,sum);
    }

    bool canPartition(vector<int>& nums) {

        if( nums.size()<=1 ){
            return false;
        }
        int sum = 0;
        for(int i = 0;i < nums.size();i ++){
            sum += nums[i];
        }
        if( sum%2!=0 ){
            return false;
        }
        this->nums = nums;
        return findw( 0,sum/2 );
        return true;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {1, 5, 11, 5};
    cout << Solution1.canPartition(nums) << endl;
    return 0;
}
