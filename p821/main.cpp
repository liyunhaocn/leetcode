#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int N = S.size();
        vector<int> ans(S.size());
        int prev = INT_MIN / 2;

        for (int i = 0; i < N; ++i) {
            if (S[i] == C) prev = i;
            ans[i] = i - prev;
        }

        prev = INT_MAX / 2;
        for (int i = N-1; i >= 0; --i) {
            if (S[i] == C) prev = i;
            ans[i] = min(ans[i], prev - i);
        }
        return ans;
    }
};




int main()
{
    Solution Solution1;
    vector<int> ret = Solution1.shortestToChar("loveleetcode",'e');
    for(auto i:ret){
        debug(i)
    }
    return 0;
}
