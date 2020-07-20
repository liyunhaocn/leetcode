#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int x=A.size();
        int y=A[0].size();
        vector<vector<int>> B( x,vector<int>(y) );
        for (int i=0;i<x;i++){
            for (int j=0;j<y;j++){
                B[i][y-j-1]=1-A[i][j];   //从后往前赋值，同时取反
            }
        }
        return B;
    }
};



int main()
{
    Solution Solution1;
    cout << Solution1.flipAndInvertImage() << endl;
    return 0;
}
