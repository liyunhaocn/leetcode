#include <iostream>
#include <vector>

using namespace std;

#define debug(c) cout<<#c<<": "<<c<<endl;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26,0);
        for( int i = 0;i < s.size();i ++ ){
            cnt[ s[i] - 'a' ]++;
            cnt[ t[i] - 'a' ]--;
        }
        cnt[ t[t.size()-1] - 'a'  ]--;
        for( int i=0;i<26;i++ ){
            if( cnt[i] == -1){
                return 'a' + i;
            }
        }
        return 'a';
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.findTheDifference("abcd","abcde") << endl;
    return 0;
}
