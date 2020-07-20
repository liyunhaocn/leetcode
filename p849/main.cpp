#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int pos = -1;
        int ret = -1;
        for( int i=0;i<seats.size();i++ ){
            if( seats[i] == 0 ){
                if( pos == -1 ){
                    pos = i;
                }else{
                    if( i == seats.size()-1 ){
                        ret = max(ret,i-pos+1);
                    }
                }
            }else{
                if( pos != -1 ){
                    if(pos == 0){
                        ret = max(ret,i );
                    }else{
                        ret = max(ret,(i-pos+1)/2 );
                    }
                    pos = -1;
                }else{
                    ;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> seats = {1,0,0,0,1,0,1};
    cout << Solution1.maxDistToClosest(seats) << endl;
    return 0;
}
