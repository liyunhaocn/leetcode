#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        map<char,int>mp;
        if(A.size() != B.size()){
            return false;
        }else{
            int cnt = 0;
            bool chong = false;
            int first=0;
            int sec=0;
            for( int i=0;i<A.size();i++ ){
                if( ++mp[A[i] ] > 1 ){
                    chong = true;
                }

                if( A[i] != B[i]){
                    cnt++;
                    if(cnt==1){
                        first = i;
                    }else if(cnt==2){
                        sec = i;
                    }
                }
            }
            //debug(cnt)
            //debug(A)
            //debug(B)
            if( cnt==2){
                swap( A[first],A[sec] );
                return A==B;
            }else if( chong && A == B ){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.buddyStrings("ab","ba") << endl;
    return 0;
}
