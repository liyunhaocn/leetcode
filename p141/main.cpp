#include <iostream>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {

        map<ListNode *,int> mp;
        ListNode * temp = head;
        while( temp!= nullptr){
            if( ++mp[ temp ] > 1 ){
                return true;
            }
            temp = temp-> next;
        }
        return false;
    }
};


int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
