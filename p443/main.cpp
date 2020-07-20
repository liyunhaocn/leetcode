#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    string int_str(int a){
        stringstream ss;
        ss<<a;
        return ss.str();
    }
    int compress( vector<char>& chars ) {
        int cnt = 1 ;
        int pos = 0;
        int begin1 =0;

        while( begin1 < chars.size() ){

            chars[pos++] = chars[begin1];
            if(begin1 == chars.size()-1){
                break;
            }
            for( int i = begin1+1 ;i < chars.size();i ++ ){

                if( chars[i] == chars[i-1] && i != chars.size()-1){
                    cnt ++;
                    continue;
                }else if( chars[i] == chars[i-1] && i == chars.size()-1){
                    cnt ++;
                    begin1 = chars.size();
                }else if( chars[i] != chars[i-1] ){
                    begin1 = i;
                }

                if( cnt > 1 ){
                    int p = 0;
                    string str = int_str(cnt);
                    while( p < str.size()){
                        chars[pos++] = str[p++];
                    }
                }
                cnt = 1;
                break ;
            }
        }
        return pos;
    }
};

int main()
{
    Solution Solution1;
    vector<char> chars = {'a','a' };
    int cnt = Solution1.compress(chars) ;
    for(int i=0;i < cnt;i++){
        cout<<chars[i];
    }
    cout<<endl;
    return 0;
}
