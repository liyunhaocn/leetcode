#include <iostream>
#include <math.h>
#include <map>
#include <string.h>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

#define debug2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl;

class Solution {
public:
    int countPrimes(int n) {
        if( n<2 ){
            return 0;
        }
        bool *pri = new bool[n+1];

        fill( pri,pri+n+1,1 );
        int sq = (int)sqrt(n) + 1 ;
        for( int i = 2;i <= sq ;i++ ){
            if(pri[i]){
                for( int j= i*i ; j<= n; j+=i ){
                    pri[j] = 0;
                }
            }
        }
        int cnt = 0;
        for( int i=2;i<n;i++ ){
            if( pri[i] ){
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.countPrimes(100) << endl;
    return 0;
}
