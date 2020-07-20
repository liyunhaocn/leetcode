#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;


class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j){
        if( i>=0 && i<board.size() && j >= 0 && j<board[0].size() && board[i][j] == 'O' ){
            board[i][j] = '#';
            dfs( board,i+1,j );
            dfs( board,i-1,j );
            dfs( board,i,j+1 );
            dfs( board,i,j-1 );
        }

    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0){
            return;
        }
        //debug(1)
        for(int i = 0;i < board[0].size();i ++){
            //debug(1)
            if( board[0][i] == 'O'){
                //debug(2)
                dfs(board,0,i);
            }
            if( board[board.size()-1][i] == 'O' ){
                //debug(3)
                dfs(board,board.size()-1,i);
            }
        }
        //debug(1)
        for(int i = 0;i < board.size();i ++){
            if(  board[i][0] == 'O'){
                dfs(board,i,0  );
            }
            if( board[ i ][ board[0].size()-1 ] ){
                dfs( board,i,board[0].size()-1 );
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == 'O' ){
                    board[i][j] = 'X';
                }else if(board[i][j] == '#' ){
                    board[i][j] = 'O';
                }
            }
        }

    }
};

int main()
{
    Solution Solution1;

    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'},
    };

    Solution1.solve(board);
    for(auto i:board){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
