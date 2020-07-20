#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    static bool cmp( string a,string b ){
        return a.size()<b.size();
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> lcnt( 26 );
        stable_sort( words.begin(),words.end(),cmp );
        for(auto i:licensePlate){
            if( i>='a' && i<= 'z' ){
                lcnt[ i-'a' ]++;
            }else if(i>='A' && i<= 'Z'){
                lcnt[ i-'A' ]++;
            }
        }

        for( string w : words ){
            vector<int> wcnt( 26);
            for( char c:w ){
                if( c >='a' && c <= 'z' ){
                    wcnt[ c-'a' ] ++;
                }else if(c >= 'A' && c <= 'Z'){
                    wcnt[ c-'A' ] ++;
                }
            }

            bool ss = true;
            for( int i=0;i<26; i++ ){
                if(wcnt[i] < lcnt[i]){
                    ss = false;
                    break;
                }
            }
            if(ss){
               return w;
            }
        }
        return "";
    }
};

int main()
{
    Solution Solution1;
    string licensePlate = "1s3 456";
    vector<string> words = {"looks","pest","stew","show"};

    cout << Solution1.shortestCompletingWord(licensePlate,words) << endl;
    return 0;
}
