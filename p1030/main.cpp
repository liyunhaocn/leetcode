#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res(R*C,vector<int>(3));//数组第三个位置存放两点的曼哈顿距离
        int num=0;
        for(int i=0;i<C;i++)
        {
            for(int j=0;j<R;j++)
            {
                res[num][0]=j;
                res[num][1]=i;
                res[num][2]=abs(r0-j)+abs(c0-i);//曼哈顿距离
                num++;
            }
        }
        sort(res.begin(),res.end(),ismax);//排序
        for(int i=0;i<num;i++)//将曼哈顿距离删除
        {
            res[i].pop_back();
        }
        return res;
    }
    static bool ismax(vector<int> &a,vector<int> &b)//根据曼哈顿距离升序排序
    {
        return a[2]<b[2];
    }
};


int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
