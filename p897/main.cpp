#include <iostream>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:
    TreeNode * head = nullptr;
    TreeNode * temp = nullptr;
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        findw(root);
        return head;
    }
    void findw( TreeNode * root){
        if( root != nullptr ){
            //debug(root->val)
            findw(root->left);
            if( head == nullptr ){
                head = root;
                temp = root;
            }else{
                temp->right = root;
                root->left = nullptr;
                temp->left = nullptr;
                temp = root;
            }
            findw(root->right);
        }
    }
};

void dis(TreeNode * root){
    if( root != nullptr ){
        debug(root->val)
        dis(root->left);
        dis(root->right);
    }
}
int main()
{
    Solution Solution1;
    TreeNode * root = new TreeNode(379);
    root ->left = new TreeNode(826);
    root =  Solution1.increasingBST(root);
    dis(root);
    return 0;
}
