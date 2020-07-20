#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    string reverseWords(string s) {
        if( s.size() == 0 ){
                //debug(1)
            return "";
        }

        stack<string> st;
        int i =0;
        while( i < s.size() && s[i]==' ' ){
            i++;
        }

        s = s.substr(i);
        if( s.size()==0 ){
            return "";
        }
        i = s.size()-1;
        while( i >= 0 && s[i] == ' ' ){
            i--;
        }
        //debug(i);
        s = s.substr( 0,i+1 );

        int pos = s.find( " " );
        while( pos != -1 ){
            st.push( s.substr( 0, pos) );

            s = s.substr( pos+1);
            while( s.size() > 0 && s[0] == ' ' ){
                s = s.substr(1);
            }
            pos = s.find( " " );
        }
        if( s.size()>0 ){
            st.push( s );
        }
        string ret = "";
        while( !st.empty() ){
            ret += st.top();
            ret += " ";
            st.pop();
        }
        ret.pop_back();
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.reverseWords("a good   example") << endl;
    return 0;
}
