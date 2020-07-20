#include <iostream>

using namespace std;

class Solution {
public:
    int cnt1(int n){
        int cnt = 0;
        while( n>0 ){
            n &= n-1;
            cnt++;
        }
        return cnt;
    }
    int hammingDistance(int x, int y) {
        return cnt1(x^y);
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.hammingDistance(3,0) << endl;
    return 0;
}
