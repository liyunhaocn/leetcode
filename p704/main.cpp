#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while( l<=r ){
            int mid = (l+r)/2;
            if( nums[mid] >target ){
                r = mid - 1;
            }else if( nums[mid] < target ){
                l = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
int main()
{
    Solution Solution1;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << Solution1.search(nums,target) << endl;
    return 0;
}
