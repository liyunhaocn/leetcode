#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    string convertToBase7(int num) {
        string ret = "";
        if( num == 0 ){
            return "0";
        }
        bool fu = (num<0);
        if(fu){
            num = -num;
        }
        while( num>0 ){
            ret = string( 1,num%7 + '0') + ret;
            num/=7;
        }
        if(fu){
            ret = string( 1,'-') + ret;
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.convertToBase7(0) << endl;
    return 0;
}
