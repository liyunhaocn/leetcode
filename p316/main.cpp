#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>cnt(256);
        vector<bool>in_right_place(256);
        for(bool i : in_right_place){
            cout<<i<<endl;
        }
        for(char c:s){
            cnt[c]++;
        }
        string res="";
        /*���ص��ַ�����ʼ��Ϊ��*/
        for(char c:s){
            cnt[c]--;
            if(in_right_place[c]){
                /*����Ѿ�����ȷλ�ã�������*/
                continue;
            }else{
                while(cnt[res.back()]>0&&c<res.back()){
                    /*˵������һ��������ʹ���ֵ����С*/
                    in_right_place[res.back()]=false;
                    res.pop_back();
                    /*������ȷλ�õı�ǲ�����ӽ���ַ�������*/
                }
                res+=c;
                in_right_place[c]=true;
                /*��ʱc�ڡ���ǰ�ġ���ȷλ��*/
            }
        }
        return res;

    }
};

int main()
{
    Solution Solution1;

    cout<<Solution1.removeDuplicateLetters("bcabc")<<endl;
    //string a = "abcdef";
    //a.pop_back();

    //cout<<a.front()<<endl;
    return 0;
}
