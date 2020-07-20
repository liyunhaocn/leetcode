
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {

    }
};

int main()
{
	ofstream openfile("test.csv", std::ios::app);
	openfile << "fdsafdsaf,dfasdfasdfas,mazx,fasdfsaf,dfasf, " <<1<<endl;
	for (int i = 1; i < 11; i++){
		openfile << "1,2,2,2,2, " <<1<<endl;
	}
	openfile.close();
	return 0;
}
