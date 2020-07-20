#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void disp( ListNode * head ){
    debug( "---------------------" );
    while( head != nullptr ){
        debug( head->val );
        head = head->next;
    }
}


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode * da = nullptr;
        ListNode * dt = nullptr;
        ListNode * temp = new ListNode(0);
        temp->next = head;
        head = temp;
        ListNode * pt = head;

        ListNode * pre = pt;
        while( pt != nullptr){
            //debug(22222)
            pt = pt->next;
            if( pt==nullptr ){
                break;
            }
            //debug( pt->val )

            if( pt->val >= x && da == nullptr ){
                da = pt;
                dt = da;

                pre->next = pt->next;
                pt = pre;
                dt->next = nullptr;
                continue;

            }else if( pt->val >= x && da != nullptr ){

                dt->next = pt;
                dt = dt->next;

                pre->next = pt->next;
                pt = pre;
                dt->next = nullptr;
                continue;
            }
            pre = pre->next;
            //debug(111)
        }
        pre ->next = da;
        return head->next;
    }
};

void inst( ListNode * ph,vector<int> ve){
    for( auto i : ve ){
        ph->next = new ListNode( i );
        ph = ph->next;
    }
    ph->next = nullptr;

}


int main()
{
    Solution Solution1;
    ListNode * head = new ListNode(0);
    ListNode * tail = head;

    vector<int> ve = { 1,4,3,2,5,2 };
    inst( tail,ve );
    head = head->next;
    //disp(head);
    head = Solution1.partition( head,3 ) ;
    //disp(head);
    return 0;
}
