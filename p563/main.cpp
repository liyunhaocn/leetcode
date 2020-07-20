#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ret = 0;
    int sret =0;
    int findTilt(TreeNode* root) {
        sum(root);
        return sret;
    }
    int sum(TreeNode* root ){
        if( root == nullptr ){
            return 0;
        }else{
            int l = sum( root->left);
            int r = sum( root->right);
            sret += abs(l-r);
            return l+r+root->val;
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.findTilt(nullptr) << endl;
    return 0;
}
