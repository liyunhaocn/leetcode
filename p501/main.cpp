#include <iostream>
#include <vector>
#include <limits.h>

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
    int retcnt = 0;
    int curcnt = 0;
    vector<int> ret;
    int pre = INT_MIN;
    vector<int> findMode(TreeNode* root) {
        if(root==nullptr){
            return ret;
        }
        findw(root);
        return ret;
    }
    void findw( TreeNode * root){
        if( root != nullptr ){
            findw(root->left);
            if( pre == root->val){
                curcnt += 1;

            }else{
                curcnt = 1;
                pre = root->val;
            }
            if( curcnt == retcnt ){
                ret.push_back( root->val );
            }else if( curcnt > retcnt ){
                ret.clear();
                ret.push_back( root->val);
                retcnt = curcnt;
            }
            findw(root->right);
        }
    }
};

int main()
{
    Solution Solution1;
    vector<int> ret = Solution1.findMode( new TreeNode(1) ) ;
    for(auto i:ret){
        debug(i)
    }
    return 0;
}
