#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0;i < nums.size();){
            if( nums[i] != i+1 && nums[ nums[i]-1 ] != nums[i] ){
                swap( nums[i], nums[ nums[i]-1 ]);
            }else{
                i++;
            }
        }
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            if( nums[i] != i+1 ){
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ret = Solution1.findDisappearedNumbers(nums) ;
    for(int i:ret){
        debug(i)
    }
    return 0;
}
