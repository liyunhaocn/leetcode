#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stdio.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum3(int k, int n) {
        find_ret({},k,n,1);
        return ret;

    }
    // k¸öÊý
    void find_ret(vector<int> temp,int k, int n,int start){
        //debug(n)
        //debug(k)
        if( n <= 0 || k<=0 ){
            return;
        }else if(k == 1 && n >= 1 && n <= 9 && n>=start ){
            temp.push_back(n);
            ret.push_back(temp);
        }else{
            for(int i=start;i<10;i++){

                temp.push_back(i);
                find_ret(temp,k-1,n-i,i+1);
                temp.pop_back();
            }
        }
    }
};

int main()
{
    Solution Solution1;

    vector<vector<int>> ret;
    ret = Solution1.combinationSum3(3,9);
    //debug(ret.size())
    for(int i = 0;i<ret.size();i++){
        for(int j=0;j < ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
