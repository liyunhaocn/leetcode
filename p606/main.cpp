#include <iostream>
#include <sstream>

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
    string int_str(int a){
        stringstream ss;
        ss<<a;
        return ss.str();
    }

    string ret = "";
    string tree2str(TreeNode* t) {
        findw(t);
        return ret;
    }
    void findw( TreeNode*t ){
        if( t != nullptr ){
            ret += int_str(t->val);
            if( t->left == nullptr && t->right == nullptr ){
                return;
            }else if( t->left != nullptr && t->right!= nullptr){
                ret += "(";
                findw(t->left);
                ret += ")";
                ret += "(";
                findw(t->right);
                ret += ")";
            }else if( t->left != nullptr && t->right== nullptr){
                ret += "(";
                findw(t->left);
                ret += ")";
            }else if( t->left == nullptr ){
                ret+= "()";
                ret += "(";
                findw(t->right);
                ret += ")";
            }
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.tree2str(nullptr) << endl;
    return 0;
}
