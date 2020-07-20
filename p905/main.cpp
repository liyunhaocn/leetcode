#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0;
        int r = A.size()-1;
        while( l<r ){

            while( l<A.size() && A[l] % 2==0 ){
                l++;
            }
            while( r>=0 && A[r] % 2==1 ){
                r--;
            }
            if( l<r ){
                swap(A[l],A[r]);
                l++;
                r--;
            }else{
                break;
            }
        }
        return A;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {0,2};
    vector<int> ret = Solution1.sortArrayByParity(nums);
    for(auto i:ret){
        debug(i)
    }
    return 0;
}
