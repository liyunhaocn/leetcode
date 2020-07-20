#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    string ss = "";
    vector<int> ret;
    map<int ,int>visit;
    int success = 0;
    vector<int> findSubstring(string s, vector<string>& words) {
        ss = s;

        if(ss.size()==0){
            return ret;
        }
        vector<int> temp;
        set<int> retTemp;
        for( int i=0;i < words.size(); i++){
            int spos = ss.find( words[i] );
            while( spos != string :: npos ){
                success = words.size();

                for( int j= 0;j<words.size();j++ ){
                    visit[j] = 0;
                }
                visit[i] = 1;
                success--;
                //debug(spos);
                //debug(words[i])
                if ( findw( words,spos+words[i].size() )){
                    retTemp.insert(spos);

                }
                //debug( spos );
                spos +=1;
                spos = ss.find( words[i] ,spos);
                //visit[i] = 0;
            }

        }
        for(auto i:retTemp){
            //debug(i);
            ret.push_back(i);
        }
        return ret;
    }


    bool findw(vector<string> words,int curPos ){
        //debug("---------")
        //debug( success );
        //debug(curPos)
        if( success == 0 ){

            return true;
        }else{

            for( int i=0;i < words.size();i++){
                //debug(words[i])
                //debug(curPos)
                //debug( ss.find( words[i], curPos)  )

                string temp = ss.substr( curPos,words[i].size() );
                if ( visit[i] == 0 && temp == words[i] ){
                    //debug( 1111 );
                    //debug(i);
                    //debug(curPos)
                    //debug(words[i])
                    ////debug( curPos )

                    visit[i] = 1;
                    success --;
                    if( findw( words, curPos + words[i].size()  ) ){
                        return true;
                    }else{
                        visit[i] = 0;
                        success ++;
                        continue;
                    }
                }
            }
            return false;

        }
    }
};

int main()
{
    Solution Solution1;
    string s = "aaaaaaaa";
    vector<string> words = {"aa","aa","aa"};

    vector<int> ret = Solution1.findSubstring(s,words);
    for(auto i : ret){
        debug(i);
    }
    return 0;
}
