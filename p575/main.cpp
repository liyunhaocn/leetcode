#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int,int> mp;
        for( auto i :candies ){
            mp[i]++;
        }
        debug(mp.size())
        return 0;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {1,2,3,3};
    cout << Solution1.distributeCandies( nums ) << endl;
    return 0;
}
