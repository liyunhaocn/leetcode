#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if( nums.size()<=2 ){
            return true;
        }
        int i = 0;
        for(i = 0;i < nums.size()-1;i ++){
            if( nums[i] > nums[i+1] ){
                if( i+1 == nums.size()-1 ){
                    return true;
                }else if( i == 0 ){
                    i++;
                    break;
                }else{
                    if( nums[i] <= nums[i+2] ){
                        i +=2 ;
                        break;
                    }else if( nums[i-1]<= nums[i+1] ){
                        i += 1;
                        break;
                    }else{
                        return false;
                    }
                }
            }
        }
        for(;i<nums.size()-1;i++){
            if( nums[i] > nums[i+1] ){
                return false;
            }
        }
        return true;
    }
};

int main()
{

    Solution Solution1;
    vector<int> nums = {4,2,1};
    cout << Solution1.checkPossibility(nums) << endl;
    return 0;
}
