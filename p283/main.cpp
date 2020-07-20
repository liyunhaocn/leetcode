#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        int nozero = 0;
        while(1){
            while( zero <nums.size() && nums[zero] != 0 ){
                zero ++;
            }
            nozero = zero+1;
            while( nozero < nums.size() && nums[nozero] == 0){
                nozero ++;
            }
            if( nozero < nums.size() && zero < nums.size() ){
                swap( nums[nozero],nums[zero] );
            }else{
                break;
            }
        }
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {0,1,0,3,12};
    Solution1.moveZeroes(nums);
    for(auto i:nums){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
