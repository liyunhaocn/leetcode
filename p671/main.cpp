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
    int minVal = 0;
    int findSecondMinimumValue(TreeNode* root) {
        if( root!=nullptr ){
            minVal = root->val;
            return findw(root);
        }
        return -1;
    }
    int findw( TreeNode * root ){
        if(root!=nullptr){
            //debug(root->val)
        }
        if(root == nullptr){
            return -1;
        }else if( root->val > minVal ){
            return root->val;
        }else{
            if( root->left!=nullptr && root->right!=nullptr){
                int t1 = findw(root->left);
                int t2 = findw(root->right);
                if( t1== -1 && t2== -1 ){
                    return -1;
                }else if( t1==-1 ){
                    return t2;
                }else if( t2==-1 ){
                    return t1;
                }else{
                    return min( t1,t2);
                }

            }else if( root->left == nullptr && root->right == nullptr ){
                return -1;
            }else if( root->left!=nullptr){
                return findw(root->left);
            }else{
                return findw(root->right);
            }
        }
        return -1;
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
    TreeNode* temp = stringToTreeNode("[5,8,5]");
    cout << Solution1.findSecondMinimumValue(temp) << endl;
    return 0;
}
