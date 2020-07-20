#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        if(nums.size()>0){
            sum.push_back(nums[0]);
        }
        for(int i=1;i<nums.size();i++){
            sum.push_back(sum[i-1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if( i==0 ){
            return sum[j];
        }else{
            return sum[j] - sum[i-1];
        }
        return 0;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
