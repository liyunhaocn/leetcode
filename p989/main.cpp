#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> B;
        if( K==0 ){
            B.push_back(0);
        }
        while( K > 0 ){
            B.insert(B.begin(),K%10);
            K /= 10;
        }
        if( A.size() < B.size()){
            swap(A,B);
        }
        int i = A.size()-1;
        int j = B.size()-1;
        int jin = 0;
        while(i>=0 && j>=0){
            int temp = A[i]+B[j]+jin;
            A[i] = temp%10;
            jin = temp/10;
            i--;
            j--;
        }

        while(i>=0 && jin==1){
            int temp = A[i] + jin;
            A[i] = temp%10;
            jin = temp/10;
            i--;
        }

        if(jin==1){
            A.insert(A.begin(),1);
        }

        return A;
    }
};


int main()
{
    Solution Solution1;

    vector<int> A = {2,1,5};
    vector<int> ret = Solution1.addToArrayForm(A,806);
    for( auto i:ret){
        cout<<i;
    }
    cout<<endl;
    return 0;
}
