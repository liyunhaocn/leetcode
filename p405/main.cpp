#include <iostream>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num==0){
            return "0";
        }
        string ret = "";
        unsigned int num1 = num;
        while( num1>0 ){
            int cur = num1%16;
            if( cur>=10 ){
                ret = string(1,cur-10+'a') + ret;
            }else{
                ret = string(1,cur+'0') + ret;
            }
            num1/=16;
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.toHex(-1) << endl;
    return 0;
}
