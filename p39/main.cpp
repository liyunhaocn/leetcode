#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> can;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        can = candidates;
        findw( {}, target,0);
        return ret;
    }

    void findw( vector<int> temp,int tar,int curpos ){
        if(  tar == 0 ){
            ret.push_back(temp);
            return;
        }else if( curpos >= can.size() || tar<0 ){
            return;
        }
        findw( temp,tar, curpos+1 );
        temp.push_back( can[ curpos ] );
        findw( temp,tar - can[curpos],curpos );
        temp.pop_back();
    }
};

int main()
{
    Solution Solution1;
    vector<int> can ={2,3,6,7};
    int tar = 7;
    vector<vector<int>> ret = Solution1.combinationSum( can,tar );
    for( auto i:ret){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
