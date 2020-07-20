#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        if(n>0 && n%4==0){
            return false;
        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.canWinNim(8) << endl;
    return 0;
}
