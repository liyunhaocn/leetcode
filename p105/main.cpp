#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
class Solution {
public:

    TreeNode* buildTree(vector<int> pr, vector<int> in) {
        if (pr.empty()) return nullptr;
        auto root = new TreeNode(pr[0]);
        auto in_mid = find(begin(in), end(in), root->val), pr_mid = next(begin(pr),  1 + in_mid - begin(in));
        root->left = buildTree(vector<int>(next(begin(pr)), pr_mid), vector<int>(begin(in), in_mid));
        root->right = buildTree(vector<int>(pr_mid, end(pr)), vector<int>(next(in_mid), end(in)));
        return root;
    }
};
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return nullptr;
        }
        TreeNode * root = new TreeNode(preorder[0]);
        vector<int>::iterator in_mid = find(begin(inorder), end(inorder), root->val);
        vector<int>::iterator pr_mid = next(begin(preorder),  1 + in_mid - begin(inorder));
        vector<int> leftpre = vector<int>(next(begin(preorder)), pr_mid);
        vector<int> leftord = vector<int>(begin(inorder), in_mid);

        root->left = buildTree( leftpre, leftord );

        vector<int> rightpre = vector<int>(pr_mid, end(preorder));
        vector<int> rightord = vector<int>(next(in_mid), end(inorder));

        root->right = buildTree(rightpre,rightord);
        return root;
    }
};


int main(){

    int pr[5] = {3,9,20,15,7};
    int in[5] = {9,3,15,20,7};
//ͨ������a�ĵ�ַ��ʼ����ע���ַ�Ǵ�0��5������ҿ����䣩

    vector<int> preorder(pr,pr+5);
    vector<int> inorder(in,in+5);
    for(auto i : preorder){
        cout<<i<<" ";
    }
    cout<<endl;;
    //cout<< * next(begin(preorder),3)<<endl;
    Solution Solution1;
    Solution1.buildTree(preorder,inorder);

return 0;
}
