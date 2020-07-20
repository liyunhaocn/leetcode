#include <iostream>

using namespace std;

class Solution {
public:
    bool isalpha( char c ){
        if( c>= 'a' && c <= 'z' ){
            return true;
        }else if(c>= 'A' && c <= 'Z'){
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string S) {
        int l=0;
        int r=S.size()-1;
        while(l<r){
            while(!isalpha(S[l])) ++l;
            while(!isalpha(S[r])) --r;
            if(l<r) swap(S[l++],S[r--]);
        }
        return S;
    }
};



int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
