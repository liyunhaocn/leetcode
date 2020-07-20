#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<sstream>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 100;
class Solution {
private:
    // �����ַ�������ѧ��ʽ
    string formula;
    // ָ�룺ָ��formula��ǰλ��
    int start = 0;
public:
    string countOfAtoms(string formula) {
        this->formula = formula;
        // �ݹ�õ���ѧ��ʽ��ÿ��ԭ�Ӽ����Ӧ�ĸ������Թ�ϣ��map��ʽ�洢
        map<string, int> relation = getAtomsRelation();
        // ���õ��Ľ��ת���ַ������������map��key���ֵ��򱣴棬���Դ�ͷ��ʼ����
        string result = "";
        for (map<string, int>::iterator it = relation.begin(); it != relation.end(); it++) {
            result += it->first;
            // ��intת��string
            if (it->second > 1) {
                stringstream ss;
                ss << it->second;
                result += ss.str();
            }
        }
        return result;
    }
    map<string, int> getAtomsRelation() {
        // ������ǰ�ݹ�Ĺ�ϣ��
        map<string, int> cur;
        while (start < formula.length()) {
            // ����'('������һ��ݹ飬Ȼ�󽫵ݹ�Ľ�����뵱ǰ��ϣ����
            if (formula[start] == '(') {
                start++;
                map<string, int> inCur = getAtomsRelation();
                for (map<string, int>::iterator it = inCur.begin(); it != inCur.end(); it++)
                    cur[it->first] += it->second;

            // ����')'������һ��ݹ飬����֮ǰ��Ҫ����������û�����֣�����У�Ҫ����ǰ��ϣ������ֵ����������ٷ���
            } else if (formula[start] == ')') {
                int j = start + 1, tempInt = 0;
                while (j < formula.length() && formula[j] <= '9' && formula[j] >= '0') {
                    tempInt *= 10;
                    tempInt += formula[j] - '0';
                    j++;
                }
                tempInt = tempInt == 0 ? 1 : tempInt;

                for (map<string, int>::iterator it = cur.begin(); it != cur.end(); it++)
                    it->second *= tempInt;

                start = j;
                return cur;

            // ������д��ĸ��ʾ�����µ�ԭ�ӣ��õ���ǰԭ��ȫ���Ͷ�Ӧ���֣����뵱ǰ��ϣ����
            } else if (formula[start] >= 'A' && formula[start] <= 'Z') {
                // �õ�ԭ��ȫ��
                int j = start + 1;
                while (j < formula.length() && formula[j] >= 'a' && formula[j] <= 'z')
                    j++;
                string tempString = formula.substr(start, j - start);

                // �õ���Ӧ����
                int tempInt = 0;
                while (j < formula.length() && formula[j] <= '9' && formula[j] >= '0') {
                    tempInt *= 10;
                    tempInt += formula[j] - '0';
                    j++;
                }
                tempInt = tempInt == 0 ? 1 : tempInt;

                // �����ϣ����
                cur[tempString] += tempInt;

                start = j;
            }
        }
        return cur;
    }
};

int main()
{
    string formula = "K4(ON(SO3)2)2";
    Solution Solution1;
    cout<<Solution1.countOfAtoms(formula)<<endl;
    return 0;
}
