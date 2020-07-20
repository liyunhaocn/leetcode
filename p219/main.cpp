#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;
        for( int i=0;i < nums.size(); i++){
            if( mp[ nums[i] ] == 0 ){
                mp[ nums[i] ] = i+1;
            }else{
                if( i+1 - mp[ nums[i] ] <=k ){
                    return true;
                }
                mp[ nums[i] ] = i+1;
            }
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;
    cout << Solution1.containsNearbyDuplicate(nums,k) << endl;
    return 0;
}
