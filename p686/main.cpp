#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int alen = A.size(),blen = B.size();
        int maxlen = 2 * alen + blen;


        if( B.size() == 0 ){
            return 1;
        }
        for( int i=0;i < A.size();i++ ){
            if( A[i] == B[0] ){
                int ap = i;
                int bp = 0;
                while( ap < maxlen && A[ap%alen] == B[bp] ){
                    ap++;
                    bp++;
                    if( bp == blen ){
                        //debug( ap )
                        return (ap)%alen == 0? (ap)/alen: (ap)/alen+1;
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution Solution1;
    string A = "a";
    string B = "aa";
    cout << Solution1.repeatedStringMatch(A,B) << endl;
    return 0;
}
