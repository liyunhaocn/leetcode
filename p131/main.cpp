#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<vector<string>> ret;
    bool ishui(string s){
        for(int i=0;i < s.size()/2;i++){
            if( s[i] != s[s.size()-1-i] ){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        findw( s,{} );
        return ret;
    }
    void findw(string s,vector<string>temp){
        if(s.size() == 0){
            ret.push_back( temp );
        }else{
            for(int i=1;i<=s.size();i++){
                string ss =  s.substr(0,i);
                if(  ishui( ss ) ){
                    temp.push_back(ss);
                    findw(s.substr( i ),temp);
                    temp.pop_back();
                }
            }
        }
    }
};


int main()
{
    Solution Solution1;
    //debug( Solution1.ishui("bab") );
    vector<vector<string>> ret = Solution1.partition("aab") ;
    for(auto i:ret){
        for(auto j :i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
