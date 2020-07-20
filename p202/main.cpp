#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        while( n!=4 ){
            if( n==1 ){
                return true;
            }
            int temp = 0;
            while( n>0 ){
                temp += (n%10)*(n%10);
                n/=10;
            }
            n = temp;
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.isHappy(19) << endl;
    return 0;
}
