#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long long> max3(3,LONG_LONG_MIN);
        for( auto i:nums ){
            if( i == max3[0] || i == max3[1] || i == max3[2]){
                continue;
            }else if( i > max3[0] ){
                max3[2] = max3[1];
                max3[1] = max3[0];
                max3[0] = i;
            }else if( i > max3[1] ){
                max3[2] = max3[1];
                max3[1] = i;
            }else if( i > max3[2] ){
                max3[2] = i;
            }else if( i < max3[2] ){
                continue;
            }
        }
        if( max3[2] == LONG_LONG_MIN ){
            return max3[0];
        }
        return max3[2];
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {2, 2, 3, 1};
    cout << Solution1.thirdMax(nums) << endl;
    return 0;
}
