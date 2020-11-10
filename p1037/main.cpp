#include <iostream>

using namespace std;

// 向量共线 (x1,y1) (x2,y2) <=> (x1*y2 == y1*x2)
class Solution {
public:
    struct ve{
        int x;
        int y;
    };

    bool isBoomerang(vector<vector<int>>& points) {
        ve a = {points[0][0],points[0][1]};
        ve b = {points[1][0],points[1][1]};
        ve c = {points[2][0],points[2][1]};
        ve a1 = {a.x-b.x,a.y-b.y};
        ve a2 = {a.x-c.x,a.y-c.y};
        return !(a1.x*a2.y == a1.y*a2.x);
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
