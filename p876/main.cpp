#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if( head == nullptr ){
            return nullptr;
        }
        ListNode* fas = head;
        ListNode* low = head;
        while( fas!= nullptr && fas->next != nullptr ){
            fas = fas->next;
            fas = fas->next;
            low = low->next;
        }
        return low;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.middleNode(nullptr) << endl;
    return 0;
}
