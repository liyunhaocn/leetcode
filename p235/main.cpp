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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || p==nullptr|| q==nullptr){
            return nullptr;
        }
        if( p->val > q->val){
            swap(p,q);
        }
        if( ( p->val == root->val || q->val == root->val )|| (p->val < root->val && q->val > root->val) ){
            return root;
        }else if(p->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }else if(p->val > root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return nullptr;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.lowestCommonAncestor(nullptr,nullptr,nullptr) << endl;
    return 0;
}
