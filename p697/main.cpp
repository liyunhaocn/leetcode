#include <iostream>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int>first;
        map<int,int>last;
        map<int,int>cnt;

        int ret = INT_MAX;

        int max1 = -1;
        vector<int> maxv;
        for( int i = 0;i < nums.size(); i++ ){
            if( ++ cnt[ nums[i] ] == 1 ){
                first[ nums[i] ] = i+1;
                last[ nums[i] ] = i+1;
            }else{
                last[ nums[i] ] = i+1;
            }

            if( cnt[ nums[i] ] > max1 ){
                    max1 = cnt[ nums[i] ];
            }
        }

        for( auto i : nums ){
            if( cnt[i] == max1 ){
                ret = min(ret,last[i]-first[i]+1);
            }
        }

        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {1, 2, 2, 3, 1};
    cout << Solution1.findShortestSubArray(nums) << endl;
    return 0;
}
