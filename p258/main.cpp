#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
       return (num-1)%9+1;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
