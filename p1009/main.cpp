#include <iostream>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        int yi = 0;
        int NN = N;
        if( N==0){
            return 1;
        }
        while( N>0 ){
            yi<<=1;
            yi+=1;
            N >>= 1;
        }
        return yi^NN;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.bitwiseComplement(5) << endl;
    return 0;
}
