#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        //debug(L)
        //debug(R)
        //debug( (root==nullptr) )
        //debug("---------")
        if( root == nullptr || L > R ){
            return nullptr;
        }else if( L > root->val){
            root->left = nullptr;
            return trimBST(root->right,L,R);
        }else if( L == root->val ){
            //debug(1)
            root->left = nullptr;
            root->right = trimBST( root->right,L+1,R );
            return root;
        }else if( R < root->val ){
            root->right = nullptr;
            return trimBST(root->left,L,R);
        }else if( R == root->val ){
            //debug(2)
            root->right = nullptr;
            root->left = trimBST( root->left,L,R-1 );
            return root;
        }else{
            root->left = trimBST( root->left,L,root->val-1 );
            root->right = trimBST( root->right,root->val+1,R );
            return root;
        }
        return nullptr;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}
void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

int stoi(string s){
    stringstream ss;
    ss<<s;
    int a;
    ss>>a;
    return a;
}
string to_string(int a){
    stringstream ss;
    ss<<a;
    return ss.str();
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}
void pre( TreeNode*temp ){
    if( temp!=nullptr ){
        debug(temp->val);
        pre( temp->left );
        pre( temp->right );
    }
}

int main()
{
    Solution Solution1;

    TreeNode*temp = stringToTreeNode("[2,1,3]");
    //pre(temp);
    temp = Solution1.trimBST(temp,1,4) ;
    pre(temp);
    return 0;
}

