#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {

        int ret1 = 0;
        int ret2 = 0;
        int st = 0;
        for(auto i:S){

            if( ret2 + widths[i-'a'] > 100 ){
                ret1 ++;
                ret2 = widths[i-'a'];
            }else{
                ret2 += widths[i-'a'];
            }

        }
        vector<int>ret(2);
        ret[0] = ret1+1;
        ret[1] = ret2;
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string S = "abcdefghijklmnopqrstuvwxyz";
    vector<int> ret =Solution1.numberOfLines(widths,S);
    for(auto i:ret){
        cout<<i<<endl;
    }
    return 0;
}
