#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    string int_str( int a){
        stringstream ss;
        ss<<a;
        return ss.str();
    }
    struct node{
        int index;
        int num;
        node(int ind,int val){
            index = ind;
            num = val;
        }
    };
    static bool cmp(node a,node b){
        return a.num > b.num;
    }
    vector<string> findRelativeRanks(vector<int>& nums) {

        vector<node> ve;
        for( int i=0;i< nums.size();i++ ){
            ve.push_back( node(i,nums[i]) );
        }
        sort( ve.begin(),ve.end(),cmp );
        vector<string> ret(nums.size(),"");
        if( nums.size()==0 ){
            return {};
        }else if(nums.size() == 1 ){
            return {"Gold Medal"};
        }else if( nums.size()==2){
            if( ve[0].index==0 ){
                return {"Gold Medal","Silver Medal"};
            }else{
                return {"Silver Medal","Gold Medal"};
            }
        }else{
            ret[ ve[0].index ] = "Gold Medal";
            ret[ ve[1].index ] = "Silver Medal";
            ret[ ve[2].index ] = "Bronze Medal";
            for(int i=3;i<nums.size();i++){
                ret[ ve[i].index ] = int_str( i+1 );
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<string> ret = Solution1.findRelativeRanks(nums) ;
    for(string i:ret){
        debug(i)
    }
    return 0;
}
