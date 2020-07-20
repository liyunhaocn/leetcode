#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26);
        if( s.size()!=t.size() ){
            return false;
        }
        for(int i=0;i<s.size();i++){
            cnt[ s[i] -'a' ]++;
            cnt[ t[i] -'a' ]--;
        }
        for(int i=0;i<26;i++){
            if( cnt[i]!=0 ){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
