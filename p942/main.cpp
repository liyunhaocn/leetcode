#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    struct node{
        int l;
        int r;
        node(int ll,int rr):l(ll),r(rr){};
    };
    vector<int> diStringMatch(string S) {

        vector<int> ret;
        if(S.size()==0){
            return ret;
        }
        int N = S.size()-1;
        int lcnt = 0;
        int cur = 0;
        for(auto i : S){
            if( i == 'D' ){
                lcnt ++ ;
            }
        }

        node low(0, lcnt-1);
        node high(lcnt, N);

        if( S[0] == 'I' ){
            low.r ++;
            high.l ++;
            ret.push_back(low.r);
            low.r--;
            cur = high.l;
        }else{
            ret.push_back( high.l );
            high.l++;
            cur = low.r;
        }

        for(auto i:S){

            if( i == 'I' ){
                if( cur == low.r ){
                    ret.push_back(high.l);
                    high.l++;
                    cur = high.l;
                }else{
                    ret.push_back(high.l);
                    high.l ++ ;
                    cur = high.l;
                }
            }else{// i== D

                if( cur == low.r ){
                    ret.push_back(low.r);
                    low.r --;
                    cur = low.r;

                }else{
                    ret.push_back(low.r);
                    low.r --;
                    cur = low.r;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> ret = Solution1.diStringMatch("DDDDDDD");
    for( auto i:ret){
        cout<<i<<endl;
    }
    return 0;
}
