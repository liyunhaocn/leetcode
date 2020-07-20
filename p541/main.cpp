#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<"; "<<x<<endl;

class Solution {
public:
    int K = 0;
    string reverseStr(string s, int k) {
        K = k;
        findw(s,1,0);
        return s;
    }
    void findw( string &s,int fan,int pos ){
        if( pos >= s.size() ){
            return;
        }else if( fan == -1){
            ;
        }else if( pos+K < s.size() && fan == 1 ){
            for( int i = pos;i < pos+K/2;i++ ){
                //debug(i)
                //debug(pos+K-1-i)
                swap( s[i],s[ 2*pos+K-1-i ] );
            }
        }else if(pos < s.size() && fan == 1 ){
            for(int i = pos; i < pos + (s.size()-pos)/2 ;i++){
                swap( s[i],s[ pos + s.size()-1-i ] );
            }
        }

        findw( s, -fan,pos+K );
    }

};

int main()
{
    Solution Solution1;
    cout << Solution1.reverseStr("abcdefg",2) << endl;
    return 0;
}
