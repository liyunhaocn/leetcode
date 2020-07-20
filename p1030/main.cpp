#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res(R*C,vector<int>(3));//���������λ�ô������������پ���
        int num=0;
        for(int i=0;i<C;i++)
        {
            for(int j=0;j<R;j++)
            {
                res[num][0]=j;
                res[num][1]=i;
                res[num][2]=abs(r0-j)+abs(c0-i);//�����پ���
                num++;
            }
        }
        sort(res.begin(),res.end(),ismax);//����
        for(int i=0;i<num;i++)//�������پ���ɾ��
        {
            res[i].pop_back();
        }
        return res;
    }
    static bool ismax(vector<int> &a,vector<int> &b)//���������پ�����������
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
