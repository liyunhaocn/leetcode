#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for(int i=0;i < A.size()-2;i++){
            if( A[i] == A[i+1] || A[i] == A[i + 2] ){
                return A[i];
            }
        }
        return A[A.size()-1];
    }
};

int main()
{
    Solution Solution1;
    vector<int> A = {};
    cout << Solution1.repeatedNTimes() << endl;
    return 0;
}
