#include <iostream>

using namespace std;

class Solution {
public:
     ListNode *detectCycle(ListNode *head) {

        map<ListNode *,int> mp;
        ListNode * temp = head;
        while( temp!= nullptr){
            if( ++mp[ temp ] > 1 ){
                return temp;
            }
            temp = temp-> next;
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
