#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> dp;
        dp.push_back(1);
        for( int i = 1;i < s.size();i ++ ){
            if( s[i] == s[i-1]){
                dp[ dp.size()-1 ]++;
            }else{
                dp.push_back(1);
            }
        }
        int ret = 0;
        for( int i = 1;i < dp.size(); i++){
            ret += min( dp[i],dp[i-1] );
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.countBinarySubstrings("10101") << endl;
    return 0;
}
