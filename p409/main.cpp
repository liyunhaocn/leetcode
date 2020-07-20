#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int longestPalindrome(string s) {
        vector<int> cnt(129,0);
        int ret = 0;
        for(int i=0;i<s.size();i++){
            if( ++cnt[ s[i] ] % 2 ==0){
                ret++;
            }
        }
        ret*=2;
        if( ret<s.size()){
            return ret+1;
        }else{
            return ret;
        }

    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.longestPalindrome("abccccdd") << endl;
    return 0;
}
