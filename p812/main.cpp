#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    double dis(vector<int>a,vector<int>b){
        return sqrt( (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]) );
    }
    double area(double a , double b , double c){
        double p = (a + b + c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ret = 0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    double a = dis( points[i],points[j] );
                    double b = dis( points[i],points[k] );
                    double c = dis( points[j],points[k] );
                    double s = area(a,b,c);
                    ret = max( ret,s );
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<vector<int> >points;
    cout << Solution1.largestTriangleArea(points) << endl;
    return 0;
}
