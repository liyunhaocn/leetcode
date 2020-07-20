#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>>ret;
        int l = 0;
        int r = l+1;
        while( l < S.size() && r < S.size() ){

            while( S[r] == S[r-1] ){
                r++;
            }
            if( r-l>=3 ){
                ret.push_back( {l,r-1} );
            }
            l = r;
            r = l+1;
        }
        return ret;

    }
};

int main()
{
    Solution Solution1;
    vector<vector<int>>  ret = Solution1.largeGroupPositions("abcdddeeeeaabbbcd");
    for( vector<int> i:ret ){
        for( int j:i ){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
