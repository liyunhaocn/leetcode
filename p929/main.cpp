#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    void removeCharsFromString( string &str, char c ) {
        string ::iterator it = str.begin();
        for( ;it != str.end(); ){
            if( *it== c){
                it = str.erase(it);
            }else{
                it++;
            }
        }
    }

    int numUniqueEmails(vector<string>& emails) {
        //string ss = "ssss.ssss.sss";
        //removeCharsFromString( ss,'.' );
        //debug(ss)
        set<string> seen ;
        for (string email: emails) {
            int i = email.find('@');
            string local = email.substr(0, i);
            string rest = email.substr(i);
            int pos = 0;
            if ( (pos = local.find('+')) != string::npos )  {
                local = local.substr(0, pos);
            }
            removeCharsFromString(local,'.');
            seen.insert(local + rest);
        }
        return seen.size();
    }
};




int main()
{
    Solution Solution1;
    vector<string> emails;
    cout << Solution1.numUniqueEmails(emails) << endl;
    return 0;
}
