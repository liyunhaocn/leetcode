#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s+s;
        ss = ss.substr(1,ss.size()-2);
        return ss.find(s)!=-1;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.repeatedSubstringPattern("abab") << endl;
    return 0;
}
