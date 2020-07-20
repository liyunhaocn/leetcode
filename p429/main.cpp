#include <iostream>
#include <queue>

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
#define debug(x) cout<<#x<<": "<<endl;
class Solution {
public:

    vector<vector<int> > levelOrder(Node* root) {
        vector<vector<int>> ret;
        queue< Node* >qu;
        vector<int> temp;
        if(root != nullptr){
            qu.push(root);
            qu.push(nullptr);
        }else{
            return ret;
        }
        while(qu.size() >= 1){
            Node * fr = qu.front();
            qu.pop();
            if( fr != nullptr ){
                debug(fr->val)
                temp.push_back( fr->val );
                for(auto i :fr->children){
                    qu.push(i);
                }
            }else if( fr == nullptr && qu.size() > 0){
                ret.push_back(temp);
                temp.clear();
                qu.push(nullptr);
            }else if( fr == nullptr && qu.size() == 0 ){
                if( temp.size()>0 ){
                    ret.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    Solution1.levelOrder(nullptr) ;
    return 0;
}
