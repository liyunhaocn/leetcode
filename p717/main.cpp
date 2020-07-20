#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if( bits.size()==0 ){
            return false;
        }else if( bits.size()==1 ){
            return true;
        }else if( bits[ bits.size() -1]==1 ){
            return false;
        }

        int i = 0;
        int pre = 0;
        for(i = 0;i < bits.size();){
            pre = i;
            if(bits[i] ==1 ){
                i += 2;
            }else{
                i+=1;
            }
        }
        if( i== bits.size() && pre == bits.size()-1 ){
            return true;
        }else{
            return false;
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    vector<int> bits = {1, 1, 1, 0,0};
    cout << Solution1.isOneBitCharacter(bits) << endl;
    return 0;
}
