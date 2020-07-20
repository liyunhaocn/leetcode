#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if( nums.size()==0 ){
            return;
        }
        //debug(nums.size() - k)
        for( int i=0;i< k;i++ ){
            int temp = nums.back();
            nums.pop_back();
            nums.insert( nums.begin(),temp );
        }
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {-1};
    Solution1.rotate(nums,2);
    return 0;
}
