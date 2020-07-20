#include <iostream>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==0){
            return false;
        }
        int type = word[0]-'a'>=0? 0 : 1;
        if( type == 1 ){
            int subt = 0;
            if( word.size()>=2 ){
                subt = word[1]-'a'>=0? 0 : 1;
            }else{
                return true;
            }
            for(int i = 2;i<word.size();i++){
                int subtt = word[i]-'a'>=0? 0 : 1;
                if( subtt != subt ){
                    return false;
                }
            }
            return true;
        }else{
            for(int i = 1;i<word.size();i++){
                int subtt = word[i]-'a'>=0? 0 : 1;
                if( subtt != type ){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.detectCapitalUse("USA") << endl;
    return 0;
}
