#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // ��ÿһλ����ͳ�Ƴ���1�Ĵ���, ������ֵĴ�����������3˵��Ψһ���ڵ�������һλ��Ϊ1, ʱ�临�Ӷ�O(32N)
        int ret = 0;
        for(int i = 0; i < 32; ++i) {
            int bitnums = 0;
            int bit = 1 << i;
            for(int num : nums) {
                if((num&bit) != 0)
                    bitnums++;
            }
            if(bitnums % 3 != 0)
                ret |= bit;
        }
        return ret;
    }
};
int main()
{
    Solution Solution1;
    int a[4]={2,2,3,2};
    vector<int> ve(a,a+4);
    cout<<Solution1.singleNumber(ve);
    return 0;
}
