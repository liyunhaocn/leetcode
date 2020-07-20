#include <iostream>

using namespace std;

int guess(int num){
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        long long low = 1;
        long long high = n;
        while(low<= high){
            long long mid = (low + high)/2;
            if( guess( mid ) == 0 ){
                return mid;
            }else if( guess( mid ) < 0 ){
                high = mid - 1;
            }else if( guess( mid ) > 0 ){
                low = mid + 1;
            }
        }
    return 0;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.guessNumber(5) << endl;
    return 0;
}
