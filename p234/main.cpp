#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void disp(ListNode * h);

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr){
            return true;
        }else if( head->next == nullptr ){
            return true;
        }
        ListNode * fast = head;
        ListNode * low = head;
        ListNode * pre = head;
        int cnt = 0;
        while(fast != nullptr){

            if( fast->next != nullptr){
                cnt = 0;
               fast = fast->next;
            }else{
                break;
            }
            if( fast->next != nullptr){
               cnt = 1;
               fast = fast->next;
            }else{
                break;
            }

            pre = low;
            low = low->next;
        }
        //debug(low->val)
        //debug("---+++---")
        //pre = low;
        low = low->next;
        //debug(pre->val)
        //debug(low->val)
        //debug("------")

        if( cnt%2 == 1 ){

            delete( pre->next );
            pre->next = nullptr;
        }else{
            pre = pre->next;
            pre->next = nullptr;
        }

        pre = low;
        //debug(pre->val)
        //debug(low->val)
        if( low->next == nullptr ){
            if( head->val == low->val ){
                return true;
            }else{
                return false;
            }
        }

        low = low->next;
        pre->next = nullptr;

        ListNode * ne = low->next;
        //debug(pre->val)
        while( low != nullptr ){
            //debug(1)
            low->next = pre;
            pre = low;
            if( ne != nullptr ){
                low = ne;
            }else{
                break;
            }
            ne = low->next;
        }
        //disp(head);
        //disp(low);
        while( low!=nullptr && head!=nullptr ){
            if( low->val != head->val ){
                return false;
            }
            low = low->next;
            head = head->next;
        }
        return true;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

int stoi(string s){
    stringstream ss;
    ss<<s;
    int a;
    ss>>a;
    return a;
}
vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}
void disp(ListNode * h){
    while(h!=nullptr){
        debug(h->val);
        h = h->next;
    }
}
int main()
{
    Solution Solution1;
    ListNode * head = stringToListNode("[1,1]");
    //disp(head);
    cout << Solution1.isPalindrome(head) << endl;
    return 0;
}
