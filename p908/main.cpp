#include <iostream>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min1 = A[0], max1 = A[0];
        for (int x: A) {
            min1 = min(min1, x);
            max1 = max(max1, x);
        }
        return max(0, max1 - min1 - 2*K);
    }
};


int main()
{
    Solution Solution1;
    cout << Solution1.smallestRangeI() << endl;
    return 0;
}
