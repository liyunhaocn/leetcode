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
    vector<double>ret;
    vector<double> averageOfLevels(TreeNode* root) {
        if( root!=nullptr ){
            findw({root});
        }
        return ret;
    }
    void findw( vector<TreeNode*> cur){
        if( cur.size()==0 ){
            return;
        }
        double temp =0 ;
        vector<TreeNode*> next;
        for( auto i :  cur){
            temp += (double)i->val;
            if( i->left!=nullptr ){
                next.push_back(i->left);
            }
            if( i->right!=nullptr ){
                next.push_back(i->right);
            }
        }
        ret.push_back( temp/cur.size() );
        findw( next );
    }
};

int main()
{
    Solution Solution1;
    Solution1.averageOfLevels(nullptr);
    return 0;
}
