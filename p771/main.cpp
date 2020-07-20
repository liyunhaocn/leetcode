#include <iostream>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ret = 0;
        for(auto i:S){
            if( J.find(i) != string::npos ){
                ret++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.numJewelsInStones( "aA","aAAbbbb" ) << endl;
    return 0;
}
