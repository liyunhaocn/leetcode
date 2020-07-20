#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n >= 5) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.trailingZeroes(125) << endl;
    return 0;
}
