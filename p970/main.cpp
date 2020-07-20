#include <iostream>
#include <set>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> seen;
        for (int i = 0; i < 32 && int( pow(x, i)) <= bound; ++i){
            for (int j = 0;j < 32 && int( pow(y, j)) <= bound; ++j) {
                int v = (int) pow(x, i) + (int) pow(y, j);

                if (v <= bound){
                    seen.insert(v);
                }
            }
        }
        vector<int>ret;
        for(auto i:seen){
            ret.push_back(i);
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    Solution1.powerfulIntegers(1,2,1000000) ;
    return 0;
}
