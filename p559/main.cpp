#include <iostream>
#include <vector>

using namespace std;

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
    int maxDepth(Node* root) {
        if( root == nullptr){
            return 0;
        }else{
            int max1 = 0;
            for( auto i:root->children ){
                max1 = max(max1,maxDepth( i ) );
            }
            return 1 + max1;
        }
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
