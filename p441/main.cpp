#include <iostream>
#include <math.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int arrangeCoins(int k) {
        long long ret = ( sqrt(1+8*(long long)k)-1)/2;
        while( ret<=k ){
            if( ret*(ret+1)/2<=k && (ret+1)*(ret+2)/2 > k ){
                return ret;
            }
            ret++;
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.arrangeCoins(8) << endl;
    return 0;
}
