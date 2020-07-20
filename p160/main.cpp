#include <iostream>
#include <map>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * ha = headA;
        ListNode * hb = headB;
        map< ListNode*,int > mp;
        while(ha != nullptr){
            mp[ha]++;
            ha = ha->next;
        }
        while(hb != nullptr){
            if( ++mp[hb] > 1 ){
                return hb;
            }
            hb = hb->next;
        }
        return nullptr;
    }
};

int main()
{
    Solution Solution1;
    ListNode *headA;
    ListNode *headB;
    cout << Solution1.getIntersectionNode( headA, headB) << endl;
    return 0;
}
