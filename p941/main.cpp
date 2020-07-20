#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {

        int pos = 1;
        bool ret = false;
        while( pos < A.size() && A[pos] > A[pos-1] ){
            ret = true;
            pos++;
        }
        if( ret == false){
            return false;
        }
        ret = false;
        while(pos < A.size() && A[pos] < A[pos-1]){
            ret = true;
            pos++;
        }
        if( ret == false){
            return false;
        }
        return pos == A.size();
    }
};

int main()
{
    Solution Solution1;
    vector<int> A = {0,3,2,1};
    cout << Solution1.validMountainArray(A) << endl;
    return 0;
}
