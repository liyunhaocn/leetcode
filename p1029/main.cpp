#include <iostream>

using namespace std;

class Solution {
    public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Sort by a gain which company has
        // by sending a person to city A and not to city B
        sort(begin(costs), end(costs),
                [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[0] - o1[1] < o2[0] - o2[1]);
        });

        int total = 0;
        int n = costs.size() / 2;

        for (int i = 0; i < n; ++i) total += costs[i][0] + costs[i + n][1];
        return total;
    }
};


int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
