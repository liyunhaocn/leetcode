#include <iostream>
#include <limits.h>

using namespace std;


//Definition for a binary tree node.
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
    int minDiffInBST(TreeNode* root) {
        findw( root );
        return ret;
    }

    void findw(TreeNode* root){
        if( root != nullptr ){
            findw( root->left );
            if( pre != INT_MIN ){
                ret = min(ret,root->val-pre);
            }

            pre = root->val;
            findw( root->right );
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.minDiffInBST() << endl;
    return 0;
}
