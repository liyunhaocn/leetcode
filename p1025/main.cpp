#include <iostream>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        return  N%2==0;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.divisorGame(5) << endl;
    return 0;
}
