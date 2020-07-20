#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
/*
class Solution {
public:
    string s,t;

    void dispve(vector<int> ve){
        for(auto i :ve){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        return findw(0,0);
    }
    int findw(int spos,int tpos){
        if(s.size()==0){
            return 0;
        }else if(tpos >= t.size()){
            return 1;
        }
        int p = spos;
        int ans = 0;
        while( ( p = s.find( t[tpos],p ) )!=-1 ){
            p++;
            ans += findw(p,tpos+1);
        }
        return ans;
    }
};
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        vector< vector<long long> >dp(s.size()+1,vector<long long>(t.size()+1, 0) );
        for(int i = 0;i < s.size();i++){
            dp[i][0] = 1;
        }
        //debug(dp.size());
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<=i && j<=t.size();j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
 /*      ��dp[i][j]��ʾs[0:i-1]����������t[0:j-1]���ֵĴ�������
 *      1.��s[i-1] == t[j-1] => dp[i][j] = dp[i-1][j-1] (��s[i-1]��t[j-1]���) + dp[i-1][j](����s[i-1],����s[i-1]��t[j-1]���)
 *      2.��s[i-1] != t[j-1] => dp[i-1][j] (ֱ������s[i-1],����s[i-1]��t[j-1]���)
 */

int main()
{
    Solution Solution1;
    string a = "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc";
    string b = "bcddceeeebecbc";
    cout<<Solution1.numDistinct(a,b)<<endl;
    return 0;
}
