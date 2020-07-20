#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        for( auto i:nums ){
            mp[i]++;
        }
        int ret = 0;
        for( auto i:nums ){
            if( mp[i+1] > 0 ){
                ret = max( ret,mp[i] + mp[i+1] );
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.findLHS() << endl;
    return 0;
}
