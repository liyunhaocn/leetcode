#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while( i<s.size() && j<t.size() ){
            if( s[i] == t[j] ){
                i++;
                j++;
            }else{
                j++;
            }
        }
        cout<<i<<endl;
        return i == s.size();
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.isSubsequence("abc","ahbgdc") << endl;
    return 0;
}
