#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ret = 0;
    int sumRootToLeaf(TreeNode* root) {
        findw(root,0);
        return ret;
    }
    void findw(TreeNode*root,int fa){
        if(root == nullptr){
            return;
        }else if( root->left == nullptr && root->right == nullptr ){
            ret += fa*2+root->val;
        }else{
            findw(root->left, fa*2+root->val );
            findw(root->right, fa*2+root->val );
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
