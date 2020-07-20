#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> ve (N+1,0);
        for( vector<int> t :trust){
            ve[ t[0] ]--;
            ve[ t[1] ]++;
        }
        for( int i = 1;i<=N; i++){
            if( ve[i] == N-1 ){
                return i;
            }
        }
        debug(ve[3])
        return -1;
    }
};

int main()
{
    Solution Solution1;
    int N = 4;
    vector<vector<int>> trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
    cout << Solution1.findJudge(N,trust) << endl;
    return 0;
}
