#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret = 0;
        if( matrix.size()==0 ){
            return 0;
        }
        vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i = 0;i < dp.size();i ++){
            if( matrix[i][0] == '1' ){
                dp[i][0] = 1;
            }else{
                dp[i][0] = 0;
            }
            ret = max(ret,dp[i][0]*dp[i][0]);
        }
        for(int i = 0;i < dp[0].size();i ++){
            if( matrix[0][i] == '1' ){
                dp[0][i] = 1;
            }else{
                dp[0][i] = 0;
            }
            ret = max(ret,dp[0][i]*dp[0][i]);
        }
        for(int i = 1;i < dp.size();i ++){
            for(int j = 1;j < dp[i].size();j ++){
                if(matrix[i][j]== '1'){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] += min( dp[i-1][j-1], min( dp[i][j-1],dp[i-1][j] ));
                ret = max(ret,dp[i][j]*dp[i][j]);
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << Solution1.maximalSquare(matrix) << endl;
    return 0;
}
