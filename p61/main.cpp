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
    void disp(ListNode* head){
        ListNode* temp = head;
        cout<<endl;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode* tail = head;

        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        }

        //debug(tail->val);
        //debug(len);
        //��λ����
        //disp(head);
        tail->next = head;
        k = k%len;//��ת����һȦ
        k = len - k;//���ŵ�
        while(k--){
            head = head->next;
            tail = tail->next;
        }

        //�ѻ���
        tail->next = nullptr;
        //disp(head);
        return head;
    }
};



int main()
{
    ListNode* p = nullptr;
    p = new ListNode(0);
    ListNode* head = p;

    for(int i=1;i<10;i++){
        p->next = new ListNode(i);
        p = p->next;
    }


    Solution Solution1;
    Solution1.rotateRight(head,3);
    return 0;
}
