#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int> > ret( A[0].size(), vector<int>(A.size() ) );
        for(int i=0;i<A.size();i++){
            for(int j = 0;j < A[i].size();j ++){
                ret[j][i] = A[i][j];
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<vector<int>> A = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout << Solution1.transpose(A) << endl;
    return 0;
}
