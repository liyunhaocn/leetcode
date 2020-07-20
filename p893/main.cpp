#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    void shift(string& A){
        for( int i=0;i < A.size();i += 2 ){
            int cur = i;
            for( int j = i+2;j < A.size();j += 2 ){
                if( A[j] < A[cur] ){
                    cur = j;
                }
            }
            if( cur != i ){
                swap(A[cur],A[i]);
            }
        }
        for( int i=1;i < A.size();i += 2 ){
            int cur = i;
            for( int j = i+2;j < A.size();j += 2 ){
                if( A[j] < A[cur] ){
                    cur = j;
                }
            }
            if( cur != i ){
                swap(A[cur],A[i]);
            }
        }

    }
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> ret;
        for(auto i:A){
            shift(i);
            ret.insert(i);
        }
        return ret.size();
    }
};

int main()
{
    Solution Solution1;
    vector<string> A = {"a","b","c","a","c","c"};
    cout << Solution1.numSpecialEquivGroups(A) << endl;
    return 0;
}
