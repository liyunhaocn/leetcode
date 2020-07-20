#include <iostream>
#include <stack>

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
    stack<int> st;
    bool ret = true;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if( root1 != nullptr && root2 != nullptr){
            leftrightroot(root1);
            rightleftroot(root2);
            if( ret == false  ){
                ;
            }else if( st.empty() ){
                ret = true;
            }else{
                ret = false;
            }
        }else if( root1 == nullptr && root2 == nullptr ){
            ret = true;
        }else{
            ret = false;
        }
        return ret;
    }

    void leftrightroot(TreeNode* root){
        if( root != nullptr ){
            leftrightroot(root->left);
            leftrightroot(root->right);
            if( root->left == nullptr && root->right == nullptr ){
                st.push( root->val );
            }
        }
    }

    void rightleftroot(TreeNode* root){
        if( root != nullptr ){
            rightleftroot(root->right);
            rightleftroot(root->left);
            if( root->left == nullptr && root->right == nullptr ){
                if( !st.empty() && st.top() == root->val ){
                    st.pop();
                }else{
                    ret = false;
                    return;
                }
                return;
            }
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
