#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = nums.size();
        sum = sum*(1+sum)/2;
        vector<int> ret;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[ nums[i]]++;
        }
        for(auto i:mp){
            if( i.second>1 ){
                ret.push_back(i.first);
            }
            sum -= i.first;
        }
        ret.push_back(sum);
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {1,2,2,4};
    for(auto i:Solution1.findErrorNums(nums)){
        cout<<i<<endl;
    }
    return 0;
}
