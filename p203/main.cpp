#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head != nullptr && head->val==val){
            return removeElements(head->next,val);
        }else if(head != nullptr && head->val != val){
            head->next = removeElements( head->next,val );
            return head;
        }else if( head == nullptr ){
            return nullptr;
        }
        return nullptr;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
