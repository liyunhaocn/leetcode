#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {

        if(a > b){
            swap(a,b);
        }
        if(b > c){
            swap(c,b);
        }

        if(a > b){
            swap(a,b);
        }

        int ab = b-a-1;
        int bc = c-b-1;

        int max1 = max(ab,bc);
        int min1 =  min(ab,bc);
        if(max1 == 0){
            return {0,0};
        }else if(min1 <= 1){
            return {1,max1+min1};
        }else if( min1 >= 2 ){
            return { 2, max1+min1};
        }


        return {min1,max1};
    }
};

int main()
{
    Solution Solution1;
    vector<int> ret = Solution1.numMovesStones(3,5,1) ;
    cout<<ret[0]<<endl;
    cout<<ret[1]<<endl;
    return 0;
}
