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

采取了类似于数组的前n项和的思路，比如sum[4] == sum[1]，那么1到4之间的和肯定为0

对于树的话，采取DFS加回溯，每次访问到一个节点，把该节点加入到当前的pathSum中
然后判断是否存在一个之前的前n项和，其值等于pathSum与sum之差
如果有，就说明现在的前n项和，减去之前的前n项和，等于sum，那么也就是说，这两个点之间的路径和，就是sum

最后要注意的是，记得回溯，把路径和弹出去

作者：a380922457
链接：https://leetcode-cn.com/problems/path-sum-iii/solution/liang-chong-fang-fa-jian-dan-yi-dong-ban-ben-by-a3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
