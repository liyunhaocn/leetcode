#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<string> split( string s,char c ){
        vector<string> ret;
        int pos = 0;
        while( ( pos=s.find(c) ) != -1 ){
            ret.push_back( s.substr(0,pos) );
            s = s.substr( pos+1 );
        }
        if(s.size()>0){
            ret.push_back(s);
        }
        return ret;
    }
    string toGoatLatin(string S) {
        map<char,int>mp;
        vector<char> yuan = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        for (char c:yuan){
            mp[c] = 1;
        }

        int t = 1;
        string ans = "";
        vector<string> ssplt = split(S,' ');
        for (string word : ssplt) {
            char first = word[0];
            if (mp[first]==1) {
                ans += word;
            } else {
                ans += word.substr(1);
                ans += word.substr(0, 1);
            }
            ans += "ma";
            for (int i = 0; i < t; i++){
                ans += "a";
            }
            t++;
            ans.append(" ");
        }
        return ans.substr(0,ans.size()-1);
    }

};



int main()
{
    Solution Solution1;
    cout << Solution1.toGoatLatin("I speak Goat Latin") << endl;
    return 0;
}
