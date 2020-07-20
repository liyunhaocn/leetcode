#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string ss) {
        int s = 0;
        int e = ss.size()-1;
        while( s<=e ){
            if(ss[s] != ss[e]){
                return findw(ss,s+1,e) || findw(ss,s,e-1);
            }
            s++;
            e--;
        }
        return true;
    }
    bool findw( string ss,int s,int e ){
        while( s<=e ){
            if(ss[s] != ss[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.validPalindrome("") << endl;
    return 0;
}
