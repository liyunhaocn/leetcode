#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if( s.size()==0 ){
            return -1;
        }
        int cur = 0;
        vector<int> cnt(26,0);
        for(int i=0;i<s.size();i++){
            cnt[ s[i] - 'a' ]++;
            while( cur < s.size() && cnt[ s[cur] - 'a' ] > 1 ){
                cur++;
            }
            if( cur == s.size() ){
                return -1;
            }
        }
        return cur;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.firstUniqChar("loveleetcode") << endl;
    return 0;
}
