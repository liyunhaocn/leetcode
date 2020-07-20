#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if( nums.size() == 0 ){
            return 1;
        }

        for(int i=0;i < nums.size();){
            if( nums[i]>=0 && nums[i] < nums.size() && i != nums[i] && nums[i] != nums[ nums[i]] ){
                swap( nums[i] ,nums[nums[i]] );
            }else{
                i++;
            }
        }


        for(int i=1;i<nums.size();i++){
            if( i!=nums[i] ){
                return i;
            }
        }
        if( nums[0] == nums.size() ){
            return nums.size()+1;
        }
        return nums.size();
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {1,1};

    cout << Solution1.firstMissingPositive(nums) << endl;
    return 0;
}
