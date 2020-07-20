#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
    bool valueh(int a,int b){
        if( a*10+b <= 23){
            return true;
        }else{
            return false;
        }
    }

    bool valuem(int a,int b){
        if( a*10+b <= 59){
            return true;
        }else{
            return false;
        }
    }

    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(),A.end());
        string ret = "";
        int max1 = -1;
        do{
            if( valueh(A[0],A[1]) && valuem(A[2],A[3]) ){
                if( (A[0]*10+A[1])*60 + A[2]*10 + A[3] > max1){
                    max1 = (A[0]*10+A[1])*60 + A[2]*10 + A[3];
                    ret="";
                    ret += A[0]+'0';
                    ret += A[1]+'0';
                    ret += ':';
                    ret += A[2]+'0';
                    ret += A[3]+'0';
                }
            }
        }while(next_permutation( A.begin(),A.end() ) );
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> A = {1,2,3,4};
    cout << Solution1.largestTimeFromDigits(A) << endl;
    return 0;
}
