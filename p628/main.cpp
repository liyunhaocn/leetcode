#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if( nums.size() < 3 ){
            return 0;
        }
        sort( nums.begin(),nums.end(),cmp );
        int ret = 1;
        int cnt = 0;
        for( int i=0;i < nums.size();i++){
            if( nums[i] > 0 ){
                cnt++;
            }else{
                break;
            }
        }
        ret = nums[0];
        ret*=max(nums[ nums.size()-1 ]*nums[ nums.size()-2],nums[1]*nums[2]);
        return ret;
    }
    static bool cmp(int a,int b){
        return a > b;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {1,2,3};
    cout << Solution1.maximumProduct(nums) << endl;
    return 0;
}
