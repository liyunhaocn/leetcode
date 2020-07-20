#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define debug(c) cout<<#c<<": "<<c<<endl;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        int cnt = 0;
        if( k<0){
            return 0;
        }else if( k == 0 ){
            for(auto i:nums){
                if( ++ mp[i]>1){
                    cnt++;
                    mp[i] = -10002;
                }
            }
            return cnt;
        }
        nums.push_back(-100000000);
        sort( nums.begin(),nums.end() );
        for(auto i:nums){
            mp[i] = 1;
        }

        for(int i = 1;i < nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if( mp[ nums[i]+k ] ==1 ){
                    cnt++;
                }
                if( mp[ nums[i]-k ] ==1 ){
                    cnt++;
                }
            }else{
                ;
            }
        }
        return cnt/2;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    cout << Solution1.findPairs(nums,2) << endl;
    return 0;
}
