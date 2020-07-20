#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class KthLargest {
public:
    vector<int> numss;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        numss = nums;
        make_heap(numss.begin(),numss.end(),greater<int>()  );
        while( numss.size()>kk ){
            pop_heap(numss.begin(),numss.end(),greater<int>()  );
            numss.pop_back();
        }
    }

    int add(int val) {
        if( numss.size() < kk ){
            numss.push_back( val );
            make_heap(numss.begin(),numss.end(),greater<int>()  );
            return numss[0];
        }else if( val <= numss[0] ){
            return numss[0];
        }else{
            numss.push_back( val );
            pop_heap(numss.begin(),numss.end(),greater<int>()  );
            numss.pop_back();
            return numss[0];
        }
        return 0;
    }
};


int main()
{
    int k = 3;
    vector<int> arr = {4,5,8,2};
    KthLargest kthLargest(k,arr);

    debug( kthLargest.add(3) ); // returns 4
    debug( kthLargest.add(5) );// returns 5
    debug( kthLargest.add(10) );// returns 5
    debug( kthLargest.add(9) );// returns 8
    debug( kthLargest.add(4) );// returns 8

    return 0;
}
