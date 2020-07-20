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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode*ret = root;
        while( ret != nullptr ){
            if( ret->val > val ){
                ret = ret->left;
            }else if( ret->val < val ){
                ret = ret->right;
            }else{
                return ret;
            }
        }
        return nullptr;

    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
