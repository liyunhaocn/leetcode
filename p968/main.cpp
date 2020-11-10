#include <iostream>
#include <limits.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<(x)<<endl;

class Solution1 {//超时
public:
    int minCameraCover(TreeNode* root) {
        return min(findans(root,1,1),findans(root,0,0));
    }

    int findans(TreeNode* root,bool isPlaced,bool isCoverd){

        if(root==nullptr){
            return 0;
        }
        else{// have two children
            if(isPlaced){
                int ret = INT_MAX;
                int lp = findans(root->left,1,1);
                int lnp = findans(root->left,0,1);
                int rp = findans(root->right,1,1);
                int rnp = findans(root->right,0,1);
                ret = min(ret,lnp + rnp);
                ret = min(ret,lp + rp);
                ret = min(ret,lnp + rp);
                ret = min(ret,lp + rnp);
                return ret+1;
            }else{
                int ret = INT_MAX;
                if(isCoverd){

                    if(root->left==nullptr && root->right==nullptr){
                        return 0;
                    }else if(root->left!=nullptr && root->right!=nullptr){
                        int lp = findans(root->left,1,1);
                        int lnp = findans(root->left,0,0);
                        int rp = findans(root->right,1,1);
                        int rnp = findans(root->right,0,0);
                        ret = min(ret,lp + rp);
                        ret = min(ret,lnp + rp);
                        ret = min(ret,lp + rnp);
                        ret = min(ret,lnp + rnp);

                    }else if(root->left!=nullptr){
                        ret = min(ret,findans(root->left,1,1));
                        ret = min(ret,findans(root->left,0,0));
                    }else if(root->right!=nullptr){
                        ret = min(ret,findans(root->right,1,1) );
                        ret = min(ret,findans(root->right,0,0) );
                    }

                }else{
                    if(root->left==nullptr && root->right==nullptr){
                        return 1;
                    }else if(root->left!=nullptr && root->right!=nullptr){

                        int lp = findans(root->left,1,1);
                        int lnp = findans(root->left,0,0);
                        int rp = findans(root->right,1,1);
                        int rnp = findans(root->right,0,0);

                        ret = min(ret,lp+ rp);
                        ret = min(ret,lnp + rp);
                        ret = min(ret,lp + rnp);
                    }else if(root->left!=nullptr){
                        ret = min(ret,findans(root->left,1,1));
                    }else if(root->right!=nullptr){
                        ret = min(ret,findans(root->right,1,1) );
                    }
                }
                return ret;
            }
        }
    }
};

class Solution2 {
    int ans = 0;

    int minCameraCover(TreeNode*root) {
        if (root == nullptr) return 0;
        if (dfs(root) == 2) ans++;
        return ans;
    }

    // 0：该节点安装了监视器 1：该节点可观，但没有安装监视器 2：该节点不可观
    int dfs(TreeNode *node) {
        if (node == nullptr){
            return 1;
        }
        int left = dfs(node->left), right = dfs(node->right);
        if (left == 2 || right == 2) {
            ans++;
            return 0;
        } else if (left == 0 || right == 0){
            return 1;
        } else{
            return 2;
        }
    }
};

class Solution {
    public:
    int ans = 0;
    int minCameraCover(TreeNode*root) {
        if (root == nullptr) return 0;
        int ret = findans(root);
        if(ret==0){
            ans++;
        }
        return ans;
    }

    //返回 0 root 没有放置cam 并且没有被监控
    //返回 1 root 没有放置cam 并且被监控
    //返回 2 root 放置cam 并且被监控
    int findans(TreeNode*root){

        if(root==nullptr){
            return 1;
        }

        int left = findans(root->left);
        int right = findans(root->right);
        if( left==0 || right==0 ){
            ans ++;
            return 2;
        }
        if( left==2 || right==2 ){
            return 1;
        }
        return 0;
    }
};



int main()
{
    Solution Solution1;

    cout << Solution1.minCameraCover(nullptr) << endl;
    return 0;
}
