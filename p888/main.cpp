#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int Sa = 0;
        int Sb = 0;
        map<int,int> setb;
        for( auto i:A ){
            Sa += i;
        }
        for( auto i:B ){
            Sb += i;
            setb[i] = 1;
        }
        int sub = Sa - Sb;
        sub /= 2;
        for( auto i:A ){
            if( setb[ i-sub ] == 1 ){
                return { i,i-sub };
            }
        }
        return {};
    }
};

int main()
{
    Solution Solution1;
    vector<int> A = {1,1};
    vector<int> B = {2,2};
    vector<int> ret = Solution1.fairCandySwap(A,B);
    for(auto i:ret){
        debug(i)
    }
    return 0;
}
