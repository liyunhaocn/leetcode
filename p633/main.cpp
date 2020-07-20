#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    bool square( int c){
        if(c==1 || c==0){
            return true;
        }
        long long cc = c;
        long long r = c/2;
        long long l = 1;
        while( l<=r ){
            long long mid = (l+r)/2;
            if( mid*mid > cc){
                r = mid - 1;
            }else if( mid*mid < cc){
                l = mid + 1;
            }else if( mid*mid == cc){
                return true;
            }
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        int l = 1;
        int r = c/2;
        for(int i=0;i<=(int)sqrt(c);i++){
            if( square(i*i) && square(c-i*i) ){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.judgeSquareSum(4) << endl;
    return 0;
}
