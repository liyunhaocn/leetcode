#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* head;

    Solution(ListNode* head) {
        this->head = head;
        srand( time(0) );
    }

    /** Returns a random node's value. */
    int getRandom() {
        int cnt = 0;
        int ret = -1;

        ListNode* t = head;
        while( t!=nullptr ){
            cnt ++ ;
            if( rand()%cnt==0 ){
                ret = t->val;
            }
            t = t->next;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
