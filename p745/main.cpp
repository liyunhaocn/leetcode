#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        if( target < 0 ){
            target = -target;
        }
        int ret = (int)sqrt( target*2 );
        while( ret*(ret+1) > 2*target ){
            ret--;
        }
        if( ret*(ret+1) == 2*target ){
            return ret;
        }else{
            return ret+1;
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.reachNumber(-1) << endl;
    return 0;
}
