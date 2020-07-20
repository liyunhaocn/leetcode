#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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
    vector<int> zhong;
    map<int,TreeNode*> dizhi;
    void recoverTree(TreeNode* root) {
        if( root == nullptr ){
            return;
        }
        zhongxu(root);
        vector<int>paizhong(zhong);
        sort(paizhong.begin(),paizhong.end());
        debug( zhong.size() )
        for(int i=0;i<zhong.size();i++){
            if(zhong[i] != paizhong[i]){
                swap( dizhi[ zhong[i] ]->val,paizhong[ zhong[i] ]->val);
                cout<<"1"<<endl;
                break;
            }

        }
    }
    void zhongxu( TreeNode * rt ){
        if( rt!= nullptr ){
            zhongxu( rt->left );
            zhong.push_back(rt->val);
            dizhi[rt->val] = rt;
            zhongxu( rt->right );
        }
    }
};

int main()
{
    Solution Solution1;
    Solution1.recoverTree(nullptr);
    return 0;
}
