#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ret;
        int sum = 0;
        for(int i=0;i<A.size();i++){
            if( A[i]%2 == 0 ){
                sum += A[i];
            }
        }

        for(vector<int> pa:queries){

            int index = pa[1] ;
            int val = pa[0] ;

            if( A [ index ] % 2 == 0){
                sum -= A [ index ];
            }

            A[index] += val;
            if( A[index]%2==0 ){
                sum += A[index];
            }

            ret.push_back(sum);
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> A = {1,2,3,4};
    vector<vector<int>> queries = {
        {1,0},
        {-3,1},
        {-4,0},
        {2,3}
    };
    vector<int> ret = Solution1.sumEvenAfterQueries(A,queries);
    for(auto i:ret){
        debug(i)
    }
    return 0;
}
