#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 1;
        int j = 0;
        int icnt = 0;
        int jcnt = 0;
        name += "A";
        //debug(name)
        while( i < name.size() && j < typed.size()){
            icnt = 1;
            jcnt = 0;
            while( i < name.size() && name[i] == name[i-1] ){
                i++;
                icnt++;
            }
            while( j < typed.size() && typed[j] == name[i-1]){
                j++;
                jcnt++;
            }

            if( icnt > jcnt){
                return  false;
            }else{
                i++;
            }

        }
        if( i < name.size() || j < typed.size()-1 ){
            return false;
        }else{
            return true;
        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.isLongPressedName("pyplrz","ppyypllr") << endl;
    return 0;
}
