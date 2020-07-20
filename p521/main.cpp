#include <iostream>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b){
            return -1;
        }
        return (a.size()>b.size())?a.size():b.size();
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.findLUSlength("ab","ab") << endl;
    return 0;
}
