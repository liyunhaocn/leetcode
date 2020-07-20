#include <iostream>

using namespace std;

class Solution {
public:
    void reback( string & s ){
        int i = 0;
        while( i< s.size() && s[i] == ' ' ){
            i++;
        }
        s = s.substr(i);
    }
    int countSegments(string s) {
        reback(s);
        int pos = s.find( ' ' );
        int cnt = 0;
        while( pos != -1 ){
            s = s.substr(pos+1);
            reback(s);
            cnt++;
            pos = s.find( ' ' );
        }
        if( s.size()>0 ){
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.countSegments( "     " ) << endl;
    return 0;
}
