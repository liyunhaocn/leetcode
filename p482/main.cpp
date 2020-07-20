#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<"; "<<x<<endl;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        char * ret = new char[ (int)S.size()*2+1 ];
        int cnt = 0;
        int pos = 0;
        int rpos = S.size()*2;
        ret[rpos--] = '\0';
        for( int i = (int)S.size()-1;i>=0;i-- ){
            if( S[i]!='-' ){
                ret[rpos--] = S[i]>='a'?S[i]-32:S[i];
                cnt++;
            }
            if( cnt == K ){
                cnt = 0;
                ret[rpos--] = '-';
            }
        }

        string sret(ret+rpos+1);
        if( sret.size() > 0 &&  sret[0] == '-'){
            sret = sret.substr(1);
        }
        return sret;
    }
};

int main()
{
    Solution Solution1;

    cout << Solution1.licenseKeyFormatting("5F3Z-2e-9-w",4) << endl;
    return 0;
}
