#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<string> split(string s,char c){
        int pos = 0;
        while( s[pos] == c){
            pos++;
        }
        s = s.substr(pos);
        vector<string> ret;
        while( (pos = s.find(c) ) != string::npos ){
            ret.push_back( s.substr(0,pos) );
            s = s.substr(pos+1);
            pos = 0;
            while( s[pos] == c){
                pos++;
            }
            s = s.substr(pos);
        }
        if( s.size() > 0 ){
            ret.push_back(s);
        }
        return ret;
    }
    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int> count;
        vector<string> Asp = split(A,' ');
        for (string word: Asp){
            count[ word ] = count[word] + 1;
        }
        vector<string> Bsp = split(B,' ');
        for (string word: Bsp){
            count[ word ] = count[word] + 1;
        }

        vector<string> ans;
        for (auto i:count){
            if ( i.second == 1){
                ans.push_back(i.first);
            }
        }
        return ans ;
    }
};

int main()
{
    Solution Solution1;
    string A = "this apple is sweet";
    string B = "this apple is sour";
    vector<string> ret = Solution1.uncommonFromSentences(A,B);
    for( string i:ret){
        debug(i)
    }
    return 0;
}
