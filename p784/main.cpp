#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<string> ret;
    vector<string> letterCasePermutation(string S) {
        findw( S,0 );
        ret.push_back(S);
        return ret;
    }
    void findw(string s,int pos){
        //debug(pos)
        if( pos < s.size() ){
            if( s[pos]>='a' && s[pos]<='z'){
                //ret.push_back( s );
                findw(s,pos + 1);
                s[pos] -= 32;
                ret.push_back( s );
                findw(s,pos + 1);
            }else if( s[pos]>='A' && s[pos]<='Z'){
                //ret.push_back( s );
                findw(s,pos + 1);
                s[pos] += 32;
                ret.push_back( s );
                findw(s,pos + 1);
            }else{
                findw(s,pos + 1);
            }
        }
    }
};

int main()
{
    Solution Solution1;
    vector<string> ret = Solution1.letterCasePermutation("abc");
    for(auto i:ret){
        debug(i);
    }
    return 0;
}
