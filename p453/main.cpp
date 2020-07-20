#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()<=1){
            return 0;
        }
        sort( nums.begin(),nums.end() );
        int cnt = 0;
        for(int i=1;i<nums.size();i++){
            cnt += nums[i] - nums[0];
        }
        return cnt;
    }
};
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()<=1){
            return 0;
        }
        int Min = INT_MAX;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            Min = min( Min,nums[i] );
        }
        for(int i=0;i<nums.size();i++){
            cnt += nums[i] - Min;
        }
        return cnt;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.minMoves() << endl;
    return 0;
}
