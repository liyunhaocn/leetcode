#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
/*
class Solution {
public:
    int cnt1(int t){
        int ret = 0;
        while( t>0 ){
            t&=(t-1);
            ret++;
        }
        return ret;
    }
    bool isprim( int num){
        if (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19){
            return true;
        }else{
            return false;
        }

    }
    int countPrimeSetBits(int L, int R) {
        int ret = 0;
        for(int i=L;i<=R;i++){
            if (isprim( cnt1(i))){
                ret++;
            }
        }
        return ret;
    }
};
*/

//java
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; i++) {
                //665772质数位置上都是1
            res += 665772 >> Integer.bitCount(i) & 1;
        }
        return res;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.countPrimeSetBits(10,15) << endl;
    return 0;
}
