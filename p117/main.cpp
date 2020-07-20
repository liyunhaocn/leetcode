#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        queue< Node* > qu;
        if( root == nullptr ){
            return root;
        }
        qu.push( root );
        qu.push( nullptr );
        //root->right = nullptr;
        while( qu.size() > 1 ){
            Node *temp = qu.front();
            qu.pop();

            if( temp == nullptr ){
                qu.push( nullptr );
            }else{
                if( temp->left != nullptr){
                    qu.push( temp->left );
                }
                if( temp->right != nullptr){
                    qu.push( temp->right );
                }
                if( !qu.empty() ){
                    temp->next = qu.front();
                }
            }
            //debug(1)
        }
        return root;
        //if(  )
    }
};

int main()
{
    Solution Solution1;
    Node * rt = new Node();
    Solution1.connect( rt );
    return 0;
}
