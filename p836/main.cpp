#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int x2 = rec1[2];
        int y1 = rec1[1];
        int y2 = rec1[3];

        int xx1 = rec2[0];
        int xx2 = rec2[2];
        int yy1 = rec2[1];
        int yy2 = rec2[3];

        if( in( x1,x2,xx1,xx2 ) && in( y1,y2,yy1,yy2 ) ){
            return true;
        }else{
            return false;
        }


    }

    bool in( int x1,int x2,int x3,int x4 ){
        if( x3 >= x2 || x4<= x1){
            return false;
        }else{
            return true;
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    vector<int> rec1 = {7,8,13,15};
    vector<int>rec2 = {10,8,12,20};

    cout << Solution1.isRectangleOverlap(rec1,rec2) << endl;
    return 0;
}
