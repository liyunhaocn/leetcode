#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector <int>> zuhe(vector<int> in,int target){//target ��ϣ��ѡ��M�������,in��ѡ��ķ�Χ������ΪN
	vector<vector <int>> output;
	for(int i=0;i<pow(2,in.size());i++){
		int temp=0, count=0;
		vector<int> weishu;
		for(int j=0;j<in.size();j++){
			if((i&(1<<j))!=0){
				weishu.push_back(j);count++;}//�ҳ�������Ϊ1��λ���Լ����ǵ�λ��
		}
		if(count==target){//λ������M
		vector<int> one_case;
		for(int j=0;j<count;j++){
			temp = in.size() -1-weishu[j];
			one_case.push_back(in[temp]);
		}
		output.push_back(one_case);
		}
	}
	return output;
}
int main()
{
	vector<vector <int>> output;
	vector<int> in={1,2,3,4};
	output = zuhe(in, 1);
	for(auto i:output){
		for(auto j:i) cout<<j<<' ';
		cout<<endl;
	}
	return 0;
}
