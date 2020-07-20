#include <iostream>

using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if( A.size() != B.size() ){
            return false;
        }
        A += A;
        return A.find(B) != string::npos;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.rotateString() << endl;
    return 0;
}
