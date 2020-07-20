#include <iostream>
#include <math.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    long long findn( long long t ){
        long long ret = 0;
        ret = ( sqrt(8*t+1)-1 ) / 2;
        //debug(ret)
        if( ret*(ret+1) == 2*t ){
            return ret;
        }else if( ret*(ret+1) < 2*t ){
            return ret+1;
        }
        return 0;
    }

    int reachNumber(int target) {
        if( target < 0 ){
            target = -target;
        }
        long long ret = findn( target );
        //debug(ret)
        if( ret*(ret+1)/2 == target ){
            return ret;
        }else{
            if(( target-ret*(ret+1)/2 )%2 == 0){
                return ret;
            }else{
                ret++;
                if( ( target-ret*(ret+1)/2 )%2 == 0 ){
                    return ret;
                }else{
                    ret++;
                    if( ( target-ret*(ret+1)/2 )%2 == 0 ){
                        return ret;
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{

    Solution Solution1;
    cout << Solution1.reachNumber(15) << endl;
    return 0;
}
