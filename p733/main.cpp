#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:

    int color = 0;
    int orgin = 0;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        color = newColor;
        orgin = image[sr][sc];
        findw( image,sr,sc );
        return image;
    }
    void findw(vector<vector<int>>& image, int sr, int sc){
        //debug(sr);
        //debug(sc);
        if( sr >= 0 && sr < image.size() && sc>=0 && sc < image[0].size() && image[sr][sc] == orgin ){
            image[sr][sc] = -1;
            findw( image,sr+1,sc );
            findw( image,sr-1,sc );
            findw( image,sr,sc+1 );
            findw( image,sr,sc-1 );
            image[sr][sc] = color;
        }
    }
};

int main()
{
    Solution Solution1;
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1;
    int sc = 1;
    int newColor = 2;

    vector<vector<int>> ret = Solution1.floodFill(image,sr,sc,newColor);
    for( auto i:ret){
        for( auto j:i ){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
