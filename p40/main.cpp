#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> can;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        can = candidates;
        sort( can.begin(),can.end() );
        findw( {}, target,0);

        return ret;
    }

    void findw( vector<int> temp,int tar,int curpos ){
        if(  tar == 0 ){
            ret.push_back( temp );
            return;
        }else if( curpos >= can.size() || tar < 0 ){
            return;
        }

        for( int i = curpos;i < can.size();i++){
            if( i == curpos || can[i] != can[i-1]){
                //if(curpos==0){
                //    debug(i)
                //}
                temp.push_back( can[ i ] );
                findw( temp,tar - can[i],i+1 );
                temp.pop_back();
                //findw( temp,tar, i+1 );
            }
        }
    }

};

int main()
{
    Solution Solution1;
    vector<int> can ={10,1,2,7,6,1,5};
    int tar = 8;
    vector<vector<int>> ret = Solution1.combinationSum2( can,tar );
    for( auto i:ret){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
