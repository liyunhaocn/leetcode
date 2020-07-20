#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

        if( nums.size() == 0){
            return nums;
        }
        int row = nums.size();
        int col = nums[0].size();
        if( row*col != r*c ){
            return nums;
        }
        vector<vector<int>> ret(r,vector<int>(c,0));
        int cnt = 0;
        for( auto i:nums ){
            for(auto j:i ){
                ret[cnt/c][cnt%c] = j;
                cnt++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<vector<int>> nums;
    Solution1.matrixReshape(nums,0,0);
    return 0;
}
