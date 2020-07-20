#include <iostream>
#include <vector>

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if( t1!= nullptr &&t2 != nullptr ){
            t1->val += t2->val;
            if( t1->left != nullptr && t2->left != nullptr ){
                mergeTrees(t1->left,t2->left);
            }else if( t1->left == nullptr && t2->left != nullptr ){
                t1->left = t2->left;
            }

            if( t1->right != nullptr && t2->right != nullptr ){
                mergeTrees(t1->right,t2->right);
            }else if( t1->right == nullptr && t2->right != nullptr ){
                t1->right = t2->right;
            }
        }else if( t1 == nullptr &&t2!=nullptr){
            t1 = t2;
        }
        return t1;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.mergeTrees(nullptr,nullptr) << endl;
    return 0;
}
