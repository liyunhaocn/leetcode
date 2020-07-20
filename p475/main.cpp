#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:

    vector<int> myhea;

    int findnext(int i ){
        int l = 0;
        int r = myhea.size()-1;
        while( l <= r ){
            int mid = (l+r)/2;
            if( myhea[mid] == i ){
                return mid;
            }else if(myhea[mid] < i){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if( heaters.size()== 0 ){
            return 0;
        }
        sort(heaters.begin(),heaters.end());
        myhea = heaters;
        int ret = INT_MIN;
        for( int i = 0;i < houses.size(); i ++){
            int pre = 0;
            int next = 0;
            int cur = houses[i];
            if( cur > heaters[ heaters.size()-1 ] ){
                pre = heaters.size()-1;
                next = -1;
                ret = max(ret, cur - heaters[ heaters.size()-1 ]);
            }else{
                next = findnext(cur);
                pre = next-1;
                if( pre>=0 ){
                    int temp = min( cur - heaters[pre],heaters[next]-cur );
                    ret = max( ret, temp);
                }else{
                    ret = max( ret, heaters[next] - cur);
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> houses = {1,2,3};
    vector<int> heaters = {2};
    cout << Solution1.findRadius(houses,heaters) << endl;
    return 0;
}
