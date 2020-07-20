#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
public:
    int cnt = 0;
    int sum1 = 0;
    int pathSum(TreeNode* root, int sum) {

        if (root == nullptr) {
            return 0;
        }

        return paths(root, sum)
                + pathSum(root->left, sum)
                + pathSum(root->right, sum);
    }

    int paths( TreeNode* root, int sum ){
        if (root == nullptr) {
            return 0;
        }

        int res = 0;
        if (root->val == sum) {
            res += 1;
        }

        res += paths(root->left, sum - root->val);
        res += paths(root->right, sum - root->val);

        return res;
    }
};
*/

/*

��ȡ�������������ǰn��͵�˼·������sum[4] == sum[1]����ô1��4֮��ĺͿ϶�Ϊ0

�������Ļ�����ȡDFS�ӻ��ݣ�ÿ�η��ʵ�һ���ڵ㣬�Ѹýڵ���뵽��ǰ��pathSum��
Ȼ���ж��Ƿ����һ��֮ǰ��ǰn��ͣ���ֵ����pathSum��sum֮��
����У���˵�����ڵ�ǰn��ͣ���ȥ֮ǰ��ǰn��ͣ�����sum����ôҲ����˵����������֮���·���ͣ�����sum

���Ҫע����ǣ��ǵû��ݣ���·���͵���ȥ

���ߣ�a380922457
���ӣ�https://leetcode-cn.com/problems/path-sum-iii/solution/liang-chong-fang-fa-jian-dan-yi-dong-ban-ben-by-a3/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

*/

class Solution {
public:
    int ssum = 0;
    int ret = 0;
    map<int,int>mp;
    int pathSum(TreeNode* root, int sum) {
        ssum = sum;
        mp[0] = 1;
        findw( root,0 );
        return ret;
    }

    void findw(TreeNode* root,int cur){
        if(root!=nullptr){
            if( mp[ cur+root->val - ssum] >= 1 ){
                ret += mp[ cur+root->val - ssum];
            }
            mp[cur+root->val] += 1;
            findw( root->left,cur+root->val );
            findw( root->right,cur+root->val );
            mp[cur+root->val] -= 1;
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.pathSum(new TreeNode(0),0) << endl;
    return 0;
}
