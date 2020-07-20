#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int>ord;
    int cmp( string a,string b ){
        for( int i = 0;i < a.size() && i < b.size();i++ ){
            if( ord[ a[i]-'a' ] < ord[ b[i]-'a' ]){
                return -1;
            }else if( ord[ a[i]-'a' ] > ord[ b[i]-'a' ]){
                return 1;
            }else{
                ;
            }
        }
        if( a.size() == b.size()){
            return 0;
        }else{
            if( a.size() < b.size()){
                return -1;
            }else{
                return 1;
            }
        }

    }
    bool isAlienSorted(vector<string>& words, string order) {
        ord = vector<int>(26);
        for(int i=0;i<order.size();i++){
            ord[ order[i]-'a' ] = i;
        }
        for(int i=1;i<words.size();i++){
            if( cmp(words[i],words[i-1])<0 ){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    vector<string> words = {"apple","app"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    cout << Solution1.isAlienSorted(words,order) << endl;
    return 0;
}
