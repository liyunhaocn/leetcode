#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<string> split(string s,char t){
        vector<string> ret;
        int pos = 0;
        while( (pos = s.find(t)) != -1 ){
            ret.push_back( s.substr( 0,pos ) );
            s = s.substr(pos+1);
        }
        if( s.size()>0 ){
            ret.push_back(s);
        }
        return ret;
    }
    int str_int(string s){
        int ret = 0;
        for( auto i:s ){
            ret *= 10;
            ret += i-'0';
        }
        return ret;
    }
    string int_str( int s){
        stringstream ss;
        ss<<s;
        return ss.str();
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int> mp;
        vector<string> ret;
        for( string cp : cpdomains ){
            vector<string> vs = split(cp,' ');

            int cnt = str_int( vs[0]);
            string domins = vs[1];
            int pos = domins.size()-1;

            while( (pos = domins.rfind('.',pos)) != -1 ){
                mp[ domins.substr(pos+1) ] += cnt;
                pos--;
            }
            mp[ domins ] += cnt;
        }

        for( auto i:mp){
            string cnt = int_str( i.second );
            ret.push_back(cnt + " " + i.first);
        }

        return ret;
    }
};

int main()
{
    Solution Solution1;

    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> ret = Solution1.subdomainVisits(cpdomains);
    for(auto i:ret){
        debug(i)
    }

    return 0;
}
