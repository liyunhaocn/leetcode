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
    TreeNode * tt  = nullptr;

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if( t == nullptr ){
            return true;
        }
        tt = t;
        return find1( s );
    }
    bool find1(TreeNode* s){
        if( s==nullptr ){
            return false;
        }
        return findw(s,tt) || find1(s->left)|| find1(s->right);
    }

    bool findw(TreeNode* s, TreeNode* t){
        if( s == nullptr && t == nullptr ){
            return true;
        }else if(s != nullptr && t != nullptr && s->val == t->val){
            return findw( s->left,t->left ) && findw(s->right, t->right );
        }else{
            return false;
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
