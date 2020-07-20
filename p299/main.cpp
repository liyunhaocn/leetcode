#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    string int_str(int a){
        stringstream ss;
        ss<<a;
        return ss.str();
    }
    string getHint(string secret, string guess) {
        vector<int> cnt(10,0);
        int gong = 0;
        int cow = 0;
        for(int i=0;i<secret.size();i++){
            if( secret[i] == guess[i] ){
                gong ++;
            }
            cnt[ secret[i] - '0' ]++;
        }
        for(int i = 0 ; i<guess.size();i++){
            if( --cnt[ guess[i] - '0' ] >= 0){
                cow++;
            }
        }
        //debug(cow)
        string ret = "";
        ret += int_str(gong);
        ret += "A";
        ret += int_str(cow-gong);
        ret += "B";
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.getHint("1807","7810") << endl;
    return 0;
}
