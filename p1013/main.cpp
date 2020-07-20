#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int subsum = 0;
    vector<int>A;
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        this->A = A;
        for( int i = 0;i < A.size();i ++ ){
            sum += A[i];
        }
        if( sum%3==0 ){
            subsum = sum/3;
            return findw(1,0);
        }else{
            return false;
        }
        return false;
    }

    bool findw(int t,int pos){
        int sum = 0;


        if( t==4 && pos == A.size() ){
            return true;
        }else if( t>=4 || pos>=A.size() ){
            return false;
        }

        for( int i = pos;i < A.size();i++ ){
            sum += A[i];
            if( sum == subsum ){
                if( findw( t+1,i+1 ) == true ){
                    return true;
                }else{
                    //continue;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    vector<int> A = {3,3,6,5,-2,2,5,1,-9,4};
    cout << Solution1.canThreePartsEqualSum(A) << endl;
    return 0;
}
