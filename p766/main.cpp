#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if( matrix.size()==0 ){
            return true;
        }

        for(int i=0;i<matrix.size();i++){
            int tar1 = matrix[i][0];
            for( int j=0; i+j < matrix.size() && j < matrix[0].size(); j++ ){
                if(tar1 != matrix[i+j][j]){
                    return false;
                }
            }
        }
        for(int i=0;i < matrix[0].size();i++){
            int tar1 = matrix[0][i];
            for( int j=0; i+j < matrix[0].size() && j < matrix.size() ; j++ ){
                if(tar1 != matrix[j][i+j]){
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.isToeplitzMatrix() << endl;
    return 0;
}
