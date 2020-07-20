#include <iostream>

using namespace std;

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ret = 0;
        for(int i=0;i<guess.size();i++){
            if( guess[i] == answer[i] ){
                ret++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.game() << endl;
    return 0;
}
