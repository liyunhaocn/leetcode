#include <iostream>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int ac = 0;
        int lc = 0;
        for(int i=0;i<s.size();i++){
            if( s[i] == 'A' ){
                ac++;
            }
            if( s[i] == 'L' ){
                lc++;
            }else{
                lc=0;
            }
            if(lc>2){
                return false;
            }
        }
        return ac<=1;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.checkRecord("PPALLP") << endl;
    return 0;
}
