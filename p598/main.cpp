#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        for( int i=0;i<ops.size(); i++){
            m = min( m,ops[i][0]);
            n = min( n,ops[i][1]);
        }
        return m*n;
    }
};

int main()
{
    Solution Solution1;
    vector<vector<int>> ops;
    cout << Solution1.maxCount() << endl;
    return 0;
}
