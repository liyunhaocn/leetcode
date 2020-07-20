#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
/*
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nn(nums);
        sort(nn.begin(),nn.end());
        int s = 0;
        int e = nums.size()-1;
        while( s<nums.size() && nums[s] == nn[s] ){
            s++;
        }
        while(e>=0 && nums[e] == nn[e] ){
            e--;
        }
        if( e-s+1<0 ){
            return 0;
        }else{
            return e-s+1;
        }
    }
};
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if( nums.size()==1 ){
            return 0;
        }
        int max1 = INT_MIN;
        int min1 = INT_MAX;
        int low = nums.size()-1;
        int high = 0;
        for( int i=0;i<nums.size(); i++){
            max1 = max( max1,nums[i] );
            min1 = min( min1, nums[ nums.size()-1-i ] );
            if( nums[i] < max1 ){
                high = i;
            }
            if( nums[ nums.size()-1-i ]>min1 ){
                low = nums.size()-1-i;
            }
        }
        return high-low+1>0?high-low+1:0;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << Solution1.findUnsortedSubarray(nums) << endl;
    return 0;
}
