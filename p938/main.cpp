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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if( root == nullptr ){
            return 0;
        }else{
            if( root->val>=L && root->val<=R ){
                return root->val + rangeSumBST(root->left,L,R)
                + rangeSumBST(root->right,L,R);
            }else if( R<root->val ){
                return rangeSumBST(root->left,L,R);
            }else{
                return rangeSumBST(root->right,L,R);
            }
        }
        return 0;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
