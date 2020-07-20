#include <iostream>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for( auto &i:str ){
            if( i <= 'Z' && i >= 'A'){
                i += 32;
            }
        }
        return str;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.toLowerCase("HHHHHHHHH") << endl;
    return 0;
}
