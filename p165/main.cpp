#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int str_int( string s ){
        stringstream ss;
        ss<<s;
        int ret;
        ss>>ret;
        return ret;
    }
    vector<int> split( string s ){
        int pos = -1;
        vector<int> ret;
        pos = s.find( '.' );
        while( pos != -1 ){
            string temp = s.substr(0,pos);
            ret.push_back( str_int( temp ) );
            s = s.substr( pos+1 );
            pos = s.find( '.' );
        }
        if( s.size()>0){
            ret.push_back( str_int(s) );
        }

        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split( version1 );
        vector<int> v2 = split( version2 );
        int len = max( v1.size(),v2.size() );
        while( v1.size()< len ){
            v1.push_back( 0 );
        }
        while( v2.size()< len ){
            v2.push_back( 0 );
        }
        for( int i=0;i<v1.size() && i<v2.size();i++ ){
            if( v1[i] > v2[i] ){
                return 1;
            }else if( v1[i] < v2[i] ){
                return -1;
            }
        }
        return 0;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.compareVersion("0.1","1.1") << endl;
    return 0;
}
