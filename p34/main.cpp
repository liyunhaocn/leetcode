#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int j = nums.size()-1;
        int mid = (i+j)/2;
        vector<int> ret;
        if( nums.size()==0 ){
            return {-1,-1};
        }
        while( i < j ){
            if( nums[ mid ] < target ){
                i=mid+1;
            }else if( nums[ mid ] > target ){
                j=mid-1;
            }else{
                break;
            }
            mid = (i+j)/2;

        }

        if( nums[mid] == target ){
            i  = j = mid;
            while( i>=0 && nums[i] == target ){
                i--;
            }
            while( j< nums.size() && nums[j] == target ){
                j++;
            }
            return {i+1,j-1};
        }else{
            return {-1,-1};
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {1};
    int target = 1;
    vector<int> ret = Solution1.searchRange(nums,target);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;

}
