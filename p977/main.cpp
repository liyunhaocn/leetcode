#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int N = A.size();
        vector<int> ans(N) ;
        for (int i = 0; i < N; ++i)
            ans[i] = A[i] * A[i];

        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
