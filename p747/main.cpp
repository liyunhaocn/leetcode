#include <iostream>
#include <vector>

using namespace std;


#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = -1;
        int subi = -1;
        int posi = 0;
        for(int i=0;i < nums.size(); i++){
            if( nums[i] > maxi ){
                subi = maxi;
                maxi = nums[i];
                posi = i;
            }else if(nums[i] > subi){
                subi = nums[i];
            }
        }

        return maxi >= subi*2?posi:-1;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {0,0,3,2};
    cout << Solution1.dominantIndex(nums) << endl;
    return 0;
}
