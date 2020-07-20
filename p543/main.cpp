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
    int diameterOfBinaryTree(TreeNode* root) {
        findw(root);
        return ret;
    }
    int findw(TreeNode* root){
        if( root == nullptr ){
            return 0;
        }else if( root->left!=nullptr && root->right != nullptr ){
            int zuo = findw(root->left);
            int you = findw(root->right);
            ret = max( ret,zuo+you+2 );
            return 1 + max( zuo ,you ) ;
        }else if(root->left==nullptr && root->right == nullptr){
            return 0;
        }else if(root->left == nullptr){
            int you = findw(root->right);
            ret = max( ret,you+1 );
            return 1 + you  ;
        }else if(root->right == nullptr){
            int zuo = findw(root->left);
            ret = max( ret,zuo + 1 );
            return 1 + zuo  ;

        }else{
            return 0;
        }
        return 0;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.diameterOfBinaryTree(new TreeNode(1)) << endl;
    return 0;
}
