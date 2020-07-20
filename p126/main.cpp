#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    string beginW="";
    string endW = "";
    map<int,int> isvisit;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        beginW = beginWord;
        endW = endWord;
        vector<string>cur;
        int curPos;
        int cnt = 0;
        wordList.push_back(beginW);
        for(int i=0;i<wordList.size();i++){
            if( wordList[i] == beginW){
                cnt++;
                curPos = i;
            }else if( wordList[i] == endW){

                cnt++;
            }
        }
        if(cnt == 2){
            //debug(111)
            vector<string>cur;
            findw(wordList,ret,cur,curPos);
        }
        sort(ret.begin(),ret.end(),cmp);
        vector<vector<string>> ret1;
        for(int i=0;i<ret.size();i++){
            if( ret[i].size() == ret[0].size() ){
                ret1.push_back(ret[i]);
            }
        }
        return ret1;
    }

    static bool cmp(vector<string> a,vector<string> b){
        return a.size() < b.size();
    }
    bool isLin(string a,string b){
        if(a.size() != b.size()){
            return false;
        }
        int cnt = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                cnt++;
            }
        }
        return (cnt == 1);
    }

    void findw(vector<string> wordList,vector<vector<string>> &ret,vector<string>cur,int curPos){
        //debug(curPos);
        if( wordList[curPos]==endW){
            cur.push_back(endW);
            ret.push_back(cur);
            return;
        }else{
            //debug(isvisit[curPos])
            //isvisit[curPos] = 1;
            cur.push_back(wordList[curPos]);
            for( int i=0;i < wordList.size();i++){
                //debug(wordList[i])
                if( isvisit[i] == 0 && isLin( wordList[curPos],wordList[i] ) ){
                    //debug(i)
                    isvisit[i] = 1;
                    findw(wordList,ret,cur,i);
                    isvisit[i] = 0;

                }

            }
        }
    }
};

int main()
{
    Solution Solution1;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> ret = Solution1.findLadders(beginWord,endWord,wordList);

    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
