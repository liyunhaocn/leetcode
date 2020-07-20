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
    int v = -1;
    bool isUnivalTree(TreeNode* root) {
        if( root==nullptr){
            return true;
        }
        v = root->val;
        return findw(root);
    }
    bool findw(TreeNode * root){
        if( root != nullptr ){
            if(root->val == v){
                return findw(root->left) && findw(root->right);
            }else{
                return false;
            }
        }else{
            return true;
        }
        return false;
    }

};

int main()
{
    Solution Solution1;

    cout << Solution1.searchMatrix() << endl;
    return 0;
}
