#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        string t = "$#";
        for(auto i : s){
            t += i;
            t += "#";
            //cout<<i<<endl;
        }

        //���Գ�ʼ��Ϊ1����һ������㷨��Ч��
        vector<int>p(t.size(),1);

        int pos = 0;
        int maxlen = 0;
        int id = 0;
        int mx = 0;
        for(int i=1;i<t.size();i++){
            //���öԳ��ԣ������˸��Ӷ�
            p[i] = i<mx?min(p[2*id-i],mx-i):1;
            //����֪��λ�ÿ�ʼ����������
            while(t[i+p[i]] == t[i-p[i]]){
                p[i]++;
            }
            //����mx �� id
            if(i+p[i]>mx){
                mx = i+p[i];
                id = i;
            }
            //��¼���յĴ�
            if(p[i]>maxlen){
                maxlen = p[i];
                pos = i;
            }
        }
        //(pos - maxlen)/2 ����
        return s.substr( (pos - maxlen)/2,maxlen-1 );
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.longestPalindrome("123321")<<endl;
    return 0;
}
