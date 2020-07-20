#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m, n, row, col;
        vector<vector<int>> num=M;
        int row=M.size();
        int col=M[0].size();
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                m = 1;
                if (M[i][j]!=0){
                    n=M[i][j];
                }else{
                    n=0;
                }
                if (i>0){//ио
                    m+=1;
                    n+=M[i-1][j];
                }
                if (i<row-1){  //об
                    m+=1;
                    n+=M[i+1][j];
                }
                if (j>0){
                    m+=1;
                    n+=M[i][j-1];
                }
                if (j<col-1){
                    m+=1;
                    n+=M[i][j+1];
                }
                if (i>0&&j>0){
                    m+=1;
                    n+=M[i-1][j-1];
                }
                if (i>0&&j<col-1){
                    m+=1;
                    n+=M[i-1][j+1];
                }
                if (i<row-1&&j>0){
                    m+=1;
                    n+=M[i+1][j-1];
                }
                if (i<row-1&&j<col-1){
                    m+=1;
                    n+=M[i+1][j+1];
                }
                num[i][j]=n/m;
            }
        }
        return num;
    }
};
int main()
{
    Solution Solution1;
    cout << Solution1.imageSmoother() << endl;
    return 0;
}
