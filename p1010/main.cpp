#include <iostream>

using namespace std;

class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		int count[60] = { 0 };
		int len = time.size();
		for (int i = 0; i < len; i++)
			count[time[i] % 60]++;
		int ans = (count[0] * (count[0] - 1) + count[30] * (count[30] - 1)) >> 1;
		for (int i = 1; i < 30; i++)
			ans = ans + count[i] * count[60 - i];
		return ans;
	}
};


int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
