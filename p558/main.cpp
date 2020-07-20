#include <iostream>

using namespace std;


class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if( quadTree1 == nullptr || quadTree2 == nullptr ){
            return nullptr;
        }else if( quadTree1->isLeaf ){
            if( quadTree1->val == true ){

            }else{
                valueDate(quadTree2);
                quadTree1 = quadTree2;
            }
        }else if( quadTree2->isLeaf ){
            if( quadTree2->val == true ){
                quadTree1 = quadTree2;
                //debug(quadTree2->val)
                reLeaf( quadTree1, true);

            }else{
                ;
            }
        }else{
            quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            quadTree1->topRight =  intersect(quadTree1->topRight, quadTree2->topRight);
            quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        }
        valueDate(quadTree1);
        return quadTree1;
    }
    void reLeaf(Node* q,bool val){
        if( q == nullptr ){
            return;
        }else if( q->isLeaf ){
            q->val = val;
        }else{
            reLeaf(q->topLeft,val);
            reLeaf(q->topRight,val);
            reLeaf(q->bottomLeft,val);
            reLeaf(q->bottomRight,val);
        }
    }
    void valueDate( Node* q ){
        if( q == nullptr ){
            return;
        }else if( q->isLeaf ){
            ;
        }else {
            q->val = false;
            if( q->topLeft->isLeaf && q->topRight->isLeaf && q->bottomLeft->isLeaf && q->bottomRight->isLeaf
                && q->topLeft->val == q->topRight->val
                && q->topRight->val == q->bottomLeft->val
                && q->bottomLeft->val == q->bottomRight->val
            ){
                q->val = q->bottomLeft->val;
                q->isLeaf = true;
            }else{
                valueDate(q->topLeft);
                valueDate(q->topRight);
                valueDate(q->bottomLeft);
                valueDate(q->bottomRight);
            }

        }
    }
};

int main()
{
    Solution Solution1;

    //cout << Solution1.searchMatrix() << endl;
    return 0;
}

