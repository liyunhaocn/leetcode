#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26,0);
        for(int i=0;i < magazine.size();i++){
            cnt[ magazine[i] - 'a' ] ++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if( --cnt[ ransomNote[i] - 'a'] < 0 ){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.canConstruct("aa", "aab") << endl;
    return 0;
}
