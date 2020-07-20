#include <iostream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int left = 0, right = nums.size() - 1;
        for (; left < right; ) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    return left;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.findPeakElement() << endl;
    return 0;
}
