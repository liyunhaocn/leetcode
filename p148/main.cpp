#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> temp;
        ListNode * pt = head;
        while(pt != nullptr){
            temp.push_back(pt->val);
            pt = pt->next;
        }
        sort( temp.begin(),temp.end() );
        pt = head;
        for(auto i:temp){
            pt->val = i;
            pt = pt->next;
        }
        return head;
    }
};

ListNode * head = nullptr;

void disp(){
    ListNode *temp = head;
    while( temp ){
        debug(temp->val);
        temp = temp->next;
    }
}

void ins(int x){
    ListNode * temp = new ListNode(x);
    temp -> next = head;
    head = temp;
}

int main()
{
    Solution Solution1;
    ins(2);
    ins(1);
    ins(3);
    ins(4);
    ins(-1);
    head = Solution1.sortList(head) ;
    disp();
    return 0;
}
