#include <iostream>
#include <vector>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int strnum[26] = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
        vector<string> ret;
        for(int i = 0;i < words.size();i++){
            int type = (words[i][0] - 'a' >= 0) ? words[i][0] - 'a':words[i][0] - 'A';
            type = strnum [ type ];
            bool su = true;
            for(int j = 1;j < words[i].size();j++){
                int cur = (words[i][j] - 'a' >= 0) ? words[i][j] - 'a':words[i][j] - 'A';
                if( strnum [cur] != type){
                    su = false;
                    break;
                }
            }
            if( su == true ){
                ret.push_back( words[i] );
            }
        }
        return ret;
    }
};


int main()
{
    Solution Solution1;
    vector<string> words ={ "aaaa","Hello", "Alaska", "Dad", "Peace"};
    vector<string> ret = Solution1.findWords(words);

    for(auto i:ret){
        debug(i)
    }
    return 0;
}
