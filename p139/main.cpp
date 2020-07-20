#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,0);
        dp[0] = 1;
        int i = 1;
        while( i <= s.size() ){

            if(dp[i-1]==1 ){
                for(int j=0;j < wordDict.size();j++){
                    if(  s.find( wordDict[j],i-1) == i-1){
                        dp[ i + wordDict[j].size()-1 ] = 1;
                    }
                }
            }
            i++;

        }

        return dp[ s.size() ];

    }
};

int main()
{
    Solution Solution1;
    vector<string> disc = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    cout << Solution1.wordBreak(s,disc) << endl;
    return 0;
}
