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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        findw(root);
        return root;
    }

    void findw(TreeNode * root){
        if( root != nullptr ){
            findw(root->right);
            sum += root->val;
            root->val = sum;
            findw(root->left);
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.convertBST(nullptr) << endl;
    return 0;
}
