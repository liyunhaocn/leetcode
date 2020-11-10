#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<": "<<(x)<<endl;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        vector<string>space;
        for(int i=0;i<maxWidth;i++){
            space.push_back( string(i,' ') );
            //debug(string(i,'2'))
        }
        string temp = "";
        int tlen = 0;
        int tcnt = 0;
        int pos = 0;
        int i=0;

        for(i = 0;pos + i< words.size();){
            //debug(words[pos+i])

            if(tlen + words[pos+i].size() < maxWidth){
                tlen += words[pos+i].size() + 1;
                tcnt++;
                i++;
                continue;

            }

            if(tlen + words[pos + i].size() == maxWidth ){

                tlen += words[pos+i].size();
                tcnt++;

                int resSp = maxWidth - tlen;
                if(tcnt==1){
                    temp += words[pos];
                }else{
                    int eachlen = resSp / (tcnt-1);
                    int res = resSp % (tcnt-1);

                    for(int j=0;j < tcnt-1;j++){
                        temp += words[pos+j] + space[1] +(eachlen>0?space[eachlen]:"") +
                            (j < res?space[1] :"");
                    }
                    temp += words[pos+tcnt-1];
                }
                pos += i+1;

            }
            else{

                tlen--;
                int resSp = maxWidth - tlen;

                if(tcnt==1){
                    temp += words[pos] + space[resSp];
                }else{
                    //["Listen ","to    ","many, ","speak ","to   a","few.  "]
                    //["Listen","to    ","many, ","speak ","to   a","few.  "]
                    int eachlen = resSp / (tcnt-1);
                    int res = resSp % (tcnt-1);

                    for(int j=0;j < tcnt-1;j++){
                        temp += words[pos+j] + space[1] +(eachlen>0?space[eachlen]:"") +
                            (j < res?space[1] :"");
                    }
                    temp += words[pos+tcnt-1];
                }
                pos += i;
            }


            ret.push_back(temp);
            temp = "";
            tlen = 0;
            tcnt = 0;
            i=0;

        }

        //debug(tcnt)
            //debug(tlen)
        int resSp = maxWidth - tlen;
        if(tcnt==0){
            return ret;
        }
        if(tcnt==1){
            temp += words[pos] + " ";
            temp += space[resSp];
        }else{
            int eachlen = resSp / (tcnt-1);
            int res = resSp % (tcnt-1);

            //debug(eachlen)
            for(int j=0;j < tcnt;j++){
                temp += words[pos+j] + space[1] ;
            }
            temp += space[maxWidth-temp.size()];
        }
        ret.push_back(temp);
        //["This  idds  addn","exae   of   text","justification.  "]
        return ret;
    }
};


int main()
{
    Solution Solution1;
    cout << Solution1.searchMatrix() << endl;
    return 0;
}
