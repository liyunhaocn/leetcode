#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int temp = 0;
        int n = num;
        while(num>0){
            temp = temp*2+1;
            num/=2;
        }
        return n^temp;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.findComplement(0) << endl;
    return 0;
}
