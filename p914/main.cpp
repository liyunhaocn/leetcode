#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> cnt(10001);
        for( auto i :deck){
            cnt[i] ++;
        }
        int g = 0;
        for( int i=0;i<=10000;i++ ){

            if(cnt[i]>0){
                g = gcd( g,cnt[i] );
            }
        }
        return g >= 2 ;
    }
    int gcd(int x,int y){
        return x==0 ? y : gcd(y%x,x);
    }
};

int main()
{
    Solution Solution1;
    vector<int> deck = {1,1,2,2,2,2};
    cout << Solution1.hasGroupsSizeX(deck) << endl;
    return 0;
}
