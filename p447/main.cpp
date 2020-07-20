#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        for( int i=0;i<points.size();i++ ){
            map<int,int>mp;
            for( int j=0;j<points.size(); j++){
                if( j!=i ){
                    int dis = (points[j][0]-points[i][0])*(points[j][0]-points[i][0]);
                    dis += (points[j][1]-points[i][1])*(points[j][1]-points[i][1]);
                    ret += 2*mp[ dis ];
                    mp[dis] += 1;
                }
            }
        }
        return ret;

    }
};

int main()
{
    Solution Solution1;
    vector<vector<int>> points = { {0,0},{1,0},{2,0} };
    cout << Solution1.numberOfBoomerangs(points) << endl;
    return 0;
}
