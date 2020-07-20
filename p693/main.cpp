#include <iostream>
#include <typeinfo>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;
/*
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = n&1;
        n>>=1;

        while( n>0 ){

            if( int(n&1) == pre ){
                return false;
            }
            pre = n&1;
            n>>=1;
        }
        return true;
    }
};
*/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long temp=n^(n>>1);
        return (temp&(temp+1))==0;
    }
};

int main()
{
    Solution Solution1;
    debug( typeid(4&1) )
    cout << Solution1.hasAlternatingBits(4) << endl;
    return 0;
}
