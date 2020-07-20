#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



#define debug(x) cout<<#x<<": "<<x<<endl;
#define digit(x) x>='0' && x<='9'
#define alpha(x) x>='a' && x<='z'

class Solution {
public:
    vector<string> split(string s){
        vector<string> ret;
        int pos = 0;
        while( (pos = s.find(' ')) != string::npos ){
            ret.push_back( s.substr( 0,pos) );
            s = s.substr(pos+1);
        }
        if( s.size()>0 ){
            ret.push_back(s);
        }
        return ret;
    }

    static bool cmp(string a,string b){
        int ak = a.find(' ');
        int bk = b.find(' ');
        if( alpha(a[ak+1]) && alpha(b[bk+1]) ){
            if( a.substr(ak+1) != b.substr(bk+1)){
                return a.substr(ak+1)< b.substr(bk+1);
            }else{
                return a.substr(0,ak) < b.substr(0,bk);
            }
        }else if( digit(a[ak+1]) && digit(b[bk+1]) ){
            return false;
        }else{
            if( digit(a[ak+1]) && alpha(b[bk+1]) ){
                return false;
            }else if( alpha(a[ak+1]) && digit(b[bk+1]) ){
                return true;
            }else{
                return false;
            }
        }
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort( logs.begin(),logs.end(),cmp );
        return logs;
    }
};

int main()
{
    Solution Solution1;
    vector<string> logs = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    vector<string> ret = Solution1.reorderLogFiles(logs);
    for(auto i:ret){
        debug(i)
    }
    return 0;
}
