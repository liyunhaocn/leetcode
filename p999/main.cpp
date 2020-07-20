#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    int numRookCaptures( vector<vector<char>> & board ) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='R'){
                    return cap(board,i,j,0,1)+cap(board,i,j,0,-1)+cap(board,i,j,1,0)+cap(board,i,j,-1,0);
                }
            }
        }
        return 0;
    }
    int cap(vector<vector<char>> a,int x,int y,int dx,int dy){

        while(x>=0 && x<a.size() && y>=0 && y<a[x].size() && a[x][y]!='B'){
            if(a[x][y]=='p'){
                return 1;
            }
            x+=dx;
            y+=dy;
        }

        return 0;
    }
};

int main()
{
    Solution Solution1;
    vector<vector<char>>  board = {};
    cout << Solution1.numRookCaptures(board) << endl;
    return 0;
}
