#include <iostream>

using namespace std;

class Solution {
public:
    void re(string &s,int i,int j){
        int len = j-i+1;
        for(int pos = i;pos<i+len/2;pos++){
            swap( s[pos],s[i+j-pos] );
        }
    }
    string reverseWords(string s) {
        int i=0;
        int j=0;
        while(i < s.size()){
            j = s.find(' ',i);
            if( j < s.size() ){
                re(s,i,j-1);
            }else{
                re(s, i,s.size()-1 );
                break;
            }
            i = j+1;
            while( s[i] ==' ' ){
                i++;
            }
        }
        return s;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.reverseWords( "Let's take LeetCode contest" ) << endl;
    return 0;
}
