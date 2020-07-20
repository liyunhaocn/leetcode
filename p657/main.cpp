#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(auto i:moves){
            if( i== 'U' ){
                y-=1;
            }else if( i == 'D' ){
                y+=1;
            }else if( i == 'L' ){
                x-=1;
            }else if( i == 'R' ){
                x+=1;
            }
        }
        return x==0 && y==0;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.judgeCircle( "UD") << endl;
    return 0;
}
