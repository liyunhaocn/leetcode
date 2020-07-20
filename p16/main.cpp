#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int threeSumClosest(vector<int>& a, int tar) {

        sort(a.begin(),a.end());
        //debug(tar);
        int ret = INT_MAX;
        int ans = tar;
        for(int i=0;i < a.size()-2;i++){
            //debug(i)
            if ( abs(a[i] + two(a,i+1,tar-a[i]) - tar ) < ret ){
                ret = abs( a[i] + two(a,i+1,tar-a[i]) - tar );
                ans = a[i] + two(a,i+1,tar-a[i]);
            }
            if(ret == 0){
                cout<<a[i] + two(a,i+1,tar-a[i])<<endl;
                return a[i] + two(a,i+1,tar-a[i]);
                //return 0;
            }
        }
        return ans;
    }

    int two(vector<int> &a,int pos,int tar){
        int i = pos;
        //debug(pos);
        int cur_s = INT_MAX;
        int j = a.size()-1;
        int ret = 0;
        while(i < j){

            if( abs(a[i] + a[j] - tar) < cur_s){
                cur_s = abs(a[i] + a[j] - tar);
                ret = a[i] + a[j];
            }
            if(a[i] + a[j] < tar){
                i++;
            }else if(a[i] + a[j] > tar){
                j--;
            }else{
                return tar;

            }
            //debug(ret);
        }
        return ret;
    }

};



int main()
{
    vector<int> a = {1,1,1,1};
    Solution Solution1;
    debug( Solution1.threeSumClosest(a,0) );
    return 0;
}
