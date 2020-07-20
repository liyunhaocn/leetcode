#include <iostream>
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int ret = INT_MAX;
    int pre = INT_MIN;
    int getMinimumDifference(TreeNode* root) {
        findw( root );
        return ret;
    }
    void findw(TreeNode* root){
        if( root != nullptr ){
            findw( root->left);
            if( pre == INT_MIN){
                pre = root->val;
            }else{
                ret = min(ret,root->val - pre);
                pre = root->val;
            }
            findw(root->right);
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.getMinimumDifference(nullptr) << endl;
    return 0;
}
