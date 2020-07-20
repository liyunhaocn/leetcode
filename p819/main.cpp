#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:

    vector<string> split( string s,char t ){
        int pos = 0;
        vector<string> ret;
        for( int i=0;i<s.size(); i++){
            if( s[i]>='A'  && s[i] <= 'Z'){
                s[i] += 32;
            }else if( s[i]>='a'  && s[i] <= 'z' ) {
                ;
            }else{
                s[i] = ' ';
            }
        }
        while( s[pos] == t ){
            pos++;
        }
        s = s.substr(pos);

        while( (pos= s.find(t) ) != string::npos ){
            string temp = s.substr(0,pos);
            ret.push_back( temp );
            s = s.substr(pos+1);
            pos = 0;
            while( s[pos] == t ){
                pos++;
            }
            s = s.substr(pos);
        }
        if( s.size() > 0 ){
            ret.push_back(s);
        }
        return ret;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ret = "";
        map<string,int> mp;
        for( auto i:banned){
            mp[i] = 1;
        }
        vector<string> sp = split( paragraph,' ');
        map<string,int> cnt;
        int max1 = 0;
        for( auto i:sp ){
            //debug(i)
            if( mp[i] == 0 ){
                cnt[i] ++;
                if( cnt[i] > max1 ){
                    max1 = cnt[i];
                    ret = i;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;

    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    cout << Solution1.mostCommonWord(paragraph,banned) << endl;
    return 0;
}
