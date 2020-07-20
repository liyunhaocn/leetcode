#include <iostream>
#include <vector>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for( int i=0;i<9;i++){

            vector<int> hang(10,0);
            vector<int> lie(10,0);

            for( int j=0;j<9;j++ ){

                if( board[i][j] != '.' &&  ++hang[ board[i][j]-'0' ] > 1){
                    return false;
                }

                if( board[j][i] != '.' && ++lie[ board[j][i]-'0' ] > 1){
                    return false;
                }
            }
        }

        for( int i=0;i<3;i++ ){
            for( int j=0;j<3;j++){
                vector<int> kuai(10,0);
                for( int h = i*3; h< i*3+3; h++ ){
                    for( int l = j*3;l<j*3+3;l++ ){
                        if( board[h][l]=='.' ){
                            continue;
                        }
                        if( ++kuai[board[h][l]-'0' ]>1){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution Solution1;

    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    debug(Solution1.isValidSudoku(board) );
    return 0;
}
