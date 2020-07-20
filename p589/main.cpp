#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> ret;
    vector<int> preorder(Node* root) {
        findw(root);
        return ret;
    }
    void findw(Node*root){
        if( root!= nullptr ){
            ret.push_back( root->val );
            for( auto i:root->children ){
                findw( i );
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
