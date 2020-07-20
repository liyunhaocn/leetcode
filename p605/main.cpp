#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert( flowerbed.begin(),0 );
        flowerbed.push_back(0);
        int cnt = 0;
        for( int i=1;i < flowerbed.size()-1;i++ ){
            if( flowerbed[i-1]==0 &&flowerbed[i]==0 &&flowerbed[i+1]==0  ){
                cnt++;
                flowerbed[i] =1;
            }
        }
        return cnt>=n;
    }
};

int main()
{
    Solution Solution1;
    vector<int> flowerbed = {1,0,0,0,0,1};
    cout << Solution1.canPlaceFlowers( flowerbed,1 ) << endl;
    return 0;
}
