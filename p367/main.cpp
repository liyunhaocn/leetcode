#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {

        long long left = 1;
        long long right = num;
        while(left <= right){
            long long mid = (left+right)/2;
            if( mid*mid == num ){
                return true;
            }else if( mid*mid < num ){
                left = mid+1;
            }else if( mid*mid > num ){
                right = mid -1;
            }
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.isPerfectSquare(4) << endl;
    return 0;
}
