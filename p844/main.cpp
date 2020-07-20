#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return findw(S) == findw(T);
    }
    string findw(string s){
        int qian = 0;
        int hou = 0;
        while( hou < s.size() ){
            if(s[hou]=='#'){
                qian--;
                if(qian < 0){
                    qian = 0;
                }
            }else{
                s[qian++] = s[hou];
            }
            hou++;
        }
        return s.substr(0,qian);
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.backspaceCompare("a##c", "b") << endl;
    return 0;
}
