#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while( n >0 ){
            n--;
            ret = string ( 1, ( n %26) + 'A') + ret;
            n /= 26;
        }
        cout<<ret<<endl;
        return ret;
    }

};

int main()
{
    Solution Solution1;
    cout << Solution1.convertToTitle(52) << endl;
    return 0;
}
