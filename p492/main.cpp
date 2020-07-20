#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = (int)sqrt(area);
        if( w *w == area){
            return {w,w};
        }
        while( w>=1 ){
            if( area % w == 0 ){
                return {area/w ,w };
            }
            w--;
        }
        return {};
    }
};

int main()
{
    Solution Solution1;
    vector<int> ret = Solution1.constructRectangle(4);
    for(int i:ret){
        cout<<i<<endl;
    }
    return 0;
}
