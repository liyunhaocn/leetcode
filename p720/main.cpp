#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    string longestWord(vector<string>& words) {
        map<string,int> mp;
        sort( words.begin(),words.end() );
        int max1 = 0;
        string ret = "";
        mp[""] = 1;
        for(int i = 0;i < words.size();i ++){
            //debug( words[i] )
            //debug( words[i].substr( 0,words[i].size()-1 ) )
            //debug(mp[ words[i].substr( 0,words[i].size()-1 ) ])
            //debug( (words[i].size() >= max1) )
            if( words[i].size() >= max1 && mp[ words[i].substr( 0,words[i].size()-1 ) ] == 1 ){
                if( words[i].size() == max1 ){
                    ret = words[i] > ret?ret:words[i];
                }else{
                    ret = words[i];
                }
                max1 = words[i].size();
            }
            if( words[i].size()==1 || mp[ words[i].substr( 0,words[i].size()-1 ) ] == 1){
                mp[ words[i] ] = 1;
            }

            //debug( ret )
        }
        return ret;

    }
};

int main()
{
    Solution Solution1;
    vector<string> words = {"ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o"};
    cout << Solution1.longestWord(words) << endl;
    return 0;
}
